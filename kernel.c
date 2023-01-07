#define VGA_ADDRESS 0xB8000

#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE 15

unsigned short *terminal_buffer;
unsigned int vga_index;

unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ("in %%dx, %%al" : "=a"(ret) : "d"(port) : "memory");
    return ret;
}

void clear_screen(void) {
    int index = 0;
    while (index < 80 * 25 * 2) {
        terminal_buffer[index] = ' ';
        index += 2;
    }
}

unsigned int nl_index;
void newline(void) {
    nl_index++;
    vga_index = 80 * nl_index;
}

void print(char *str, unsigned char color) {
    int index = 0;
    while (str[index]) {
        terminal_buffer[vga_index] = (unsigned short) str[index] | (unsigned short) color << 8;
        index++;
        vga_index++;
    }
}

void println(char *str, unsigned char color) {
    print(str, color);
    newline();
}

void main(void) {
    terminal_buffer = (unsigned short*) VGA_ADDRESS;
    vga_index = 0;
    clear_screen();

    println("Hello, world", RED);

    return;
}
