#include "bobik//log.h"
#include "stm32h5xx.h"
#include <cstdio>

extern "C" int _write(int file, char *ptr, int len) {
    (void)file;
    // ITM port 0 must be enabled and TRCENA set, otherwise just drop.
    if (((ITM->TCR & ITM_TCR_ITMENA_Msk) == 0) ||
        ((ITM->TER & 1U) == 0)) {
        return len;  // pretend we wrote — caller won't care
    }
    for (int i = 0; i < len; i++) {
        // Bounded spin: ~a few microseconds max.
        // If the host can't keep up, drop the character rather than hang.
        for (uint32_t spin = 0; spin < 1000; spin++) {
            if (ITM->PORT[0].u32 != 0) break;
        }
        if (ITM->PORT[0].u32 == 0) {
            // FIFO still full — drop the rest of this chunk.
            return len;
        }
        ITM->PORT[0].u8 = (uint8_t)ptr[i];
    }
    return len;
}

void log_init(void) {
    setvbuf(stdout, nullptr, _IONBF, 0);
}
