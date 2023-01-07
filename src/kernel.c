#include "include/kernel.h"
#include "include/lib.h"
#include "include/vga.h"

void kernel_main(void) {
    terminal_initialize();

    terminal_setcolor(VGA_COLOR_LIGHT_GREEN);
    terminal_writestring("Hello, kernel World!\r");

    return;
}
