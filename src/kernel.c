#include "include/kernel.h"
#include "include/lib.h"
#include "include/vga.h"

void kernel_main(void) {
    terminal_initialize();

    while (1) {
        uint8_t key = get_char();
        char c = convert_key(key);
        if (c == 0)
            continue;
        put_char(c);
    }

    return;
}
