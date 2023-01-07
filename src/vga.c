#include "include/vga.h"

void terminal_initialize(void) {
    terminal_buffer = (unsigned short*) VGA_ADDRESS;
    vga_index = 0;
}

// TODO: Implement these methods
void terminal_setcolor(unsigned char color) { }
void terminal_putentryat(char c, unsigned char color, unsigned int x, unsigned int y) { }
void terminal_putchar(char c) { }
void terminal_write(const char *data, unsigned int size) { }
void terminal_writestring(const char *data) { }