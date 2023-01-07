#ifndef KERNEL_DRIVER_H
#define KERNEL_DRIVER_H

#define FRAMEBUFFER_ADDRESS 0xC00B8000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned char character;
    unsigned char attributes;
} screen_char;

typedef struct {
    int width;
    int height;
    screen_char *buffer;
} screen_t;

void init_graphics();
void render_framebuffer();
void clear_screen();
void draw_pixel(int x, int y, unsigned char color);
void putc(char c);
void puts(char *s);
void draw_rect(int x, int y, int width, int height, unsigned char color);

unsigned char get_pixel(int x, int y);

#ifdef __cplusplus
}
#endif

#endif // KERNEL_DRIVER_H