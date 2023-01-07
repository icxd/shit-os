#include "include/vga.h"
#include "include/lib.h"

void terminal_initialize(void) {
    terminal_buffer = (unsigned short *) VGA_ADDRESS;
    terminal_clear();
}

void terminal_setcolor(unsigned char color) {
    terminal_color = color;
}

void terminal_putentryat(char c, unsigned char color, unsigned int x, unsigned int y) {
    terminal_buffer[y * VGA_WIDTH + x] = (unsigned short) c;
}

void terminal_putchar(char c) {
    if (c == '\r') {
        vga_index = vga_index - (vga_index % VGA_WIDTH);
    } else if (c == '\b') {
        vga_index--;
        terminal_putentryat(' ', terminal_color, vga_index % VGA_WIDTH, vga_index / VGA_WIDTH);
    } else if (c == '\t') {
        vga_index += 4;
    } else if (c == '\n') {
        vga_index += VGA_WIDTH;
    } else {
        terminal_putentryat(c, terminal_color, vga_index % VGA_WIDTH, vga_index / VGA_WIDTH);
        vga_index++;
    }
}

void terminal_write(const char *data, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        terminal_putchar(data[i]);
    }
}

void terminal_writestring(const char *data) {
    terminal_write(data, strlen(data));
}

void terminal_clear(void) {
    unsigned int i = 0;
    while (i < VGA_WIDTH * VGA_HEIGHT) {
        terminal_buffer[i++] = 0;
    }
}