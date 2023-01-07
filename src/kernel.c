#include "include/kernel.h"
#include "include/lib.h"
#include "include/driver.h"
#include "include/utils.h"
#include "include/keyboard.h"

bool restart() {
    uint8_t status = inb(0x64);
    if (status & 0x02)
        return 1;
    outb(0x64, 0xFE);
    return 0;
}

void shutdown() {
    outb(0x64, 0xFE);
}

void kernel_main(void) {
    terminal_initialize();


    void* smash = malloc(696969);
    if (smash == NULL) {
        blue_screen("SEGFAULT", "Failed to allocate memory");
        return;
    }

    return;
}
