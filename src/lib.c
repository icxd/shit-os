#include "include/lib.h"
#include "include/vga.h"

void print(const char* str) {
    int index = 0;
    while (str[index]) {
        put_char(str[index]);
        index++;
    }
}

void put_char(char c) {
    terminal_buffer[vga_index] = (unsigned short) c | (unsigned short) VGA_COLOR_WHITE << 8;
    vga_index++;
}

char get_char(void) {
    return (char) terminal_buffer[vga_index];
}

// TODO: Implement these methods
size_t strlen(const char* str) { }
int strcmp(const char* str1, const char* str2) { }
char* strcpy(char* dest, const char* src) { }
char* strcat(char* dest, const char* src) { }

void* malloc(size_t size) { }
void free(void* ptr) { }

size_t read(int fd, void* buf, size_t count) { }
size_t write(int fd, const void* buf, size_t count) { }