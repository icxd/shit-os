#ifndef KERNEL_VGA_H
#define KERNEL_VGA_H

#define VGA_ADDRESS 0xB8000

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

#ifdef __cplusplus
extern "C" { /* Use C linkage for kernel_main. */
#endif

unsigned short *terminal_buffer;
unsigned int vga_index;

void terminal_initialize(void);
void terminal_setcolor(unsigned char color);
void terminal_putentryat(char c, unsigned char color, unsigned int x, unsigned int y);
void terminal_putchar(char c);
void terminal_write(const char *data, unsigned int size);
void terminal_writestring(const char *data);

#ifdef __cplusplus
}
#endif

#endif /* KERNEL_VGA_H */