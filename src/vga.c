#include "include/vga.h"
#include "include/lib.h"

void terminal_initialize(void) {
    terminal_buffer = (unsigned short *) VGA_ADDRESS;
    vga_index = 0;
    terminal_color = VGA_COLOR_WHITE;
    terminal_clear();
}

void terminal_setcolor(unsigned char color) {
    terminal_color = color;
}

void terminal_putentryat(char c, unsigned char color, unsigned int x, unsigned int y) {
    const unsigned int index = y * VGA_WIDTH + x;
    terminal_buffer[index] = (unsigned short) c | (unsigned short) color << 8;
}

void terminal_putchar(char c) {
    static unsigned int vga_i = 0;
    
    if (c == '\r') {
        vga_i = vga_i - (vga_i % VGA_WIDTH);
    } else if (c == '\b') {
        if (vga_i > 0) {
            vga_i--;
            terminal_putentryat(' ', terminal_color, vga_i % VGA_WIDTH, vga_i / VGA_WIDTH);
        }
    } else if (c == '\t') {
        vga_i += 4;
    } else if (c == '\n') {
        vga_i += VGA_WIDTH;
    } else {
        terminal_putentryat(c, terminal_color, vga_i % VGA_WIDTH, vga_i / VGA_WIDTH);
        vga_i++;
    }

    vga_index = vga_i;
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