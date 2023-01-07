#ifndef KERNEL_VGA_H
#define KERNEL_VGA_H

#include "lib.h"

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_COLOR_BLACK 0
#define VGA_COLOR_BLUE 1
#define VGA_COLOR_GREEN 2
#define VGA_COLOR_CYAN 3
#define VGA_COLOR_RED 4
#define VGA_COLOR_MAGENTA 5
#define VGA_COLOR_BROWN 6
#define VGA_COLOR_LIGHT_GREY 7
#define VGA_COLOR_DARK_GREY 8
#define VGA_COLOR_LIGHT_BLUE 9
#define VGA_COLOR_LIGHT_GREEN 10
#define VGA_COLOR_LIGHT_CYAN 11
#define VGA_COLOR_LIGHT_RED 12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_LIGHT_BROWN 14
#define VGA_COLOR_WHITE 15

#define VGA_COLOR_BACKGROUND(color) (color << 4)
#define VGA_COLOR_FOREGROUND(color) (color & 0x0F)

#ifdef __cplusplus
extern "C" { /* Use C linkage for kernel_main. */
#endif

static unsigned short *terminal_buffer;
static unsigned int vga_index;
static unsigned char terminal_color;

void terminal_initialize(void);
void terminal_setcolor(unsigned char color);
void terminal_putentryat(char c, unsigned char color, unsigned int x, unsigned int y);
void terminal_putchar(char c);
void terminal_write(const char *data, unsigned int size, uint32_t newline);
void terminal_writestring(const char *data);
void terminal_writestring_without_newline(const char *data);
void terminal_clear(void);
void terminal_set_cursor(unsigned int x, unsigned int y);
void terminal_get_cursor(unsigned int *x, unsigned int *y);

void vga_set_pixel(unsigned int x, unsigned int y, unsigned char color);

#ifdef __cplusplus
}
#endif

#endif /* KERNEL_VGA_H */