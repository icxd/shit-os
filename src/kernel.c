#include "include/kernel.h"
#include "include/lib.h"
#include "include/vga.h"

void kernel_main(void) {
    terminal_initialize();

    print("Hello, world");

    return;
}