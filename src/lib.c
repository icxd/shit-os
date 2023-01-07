#include "include/lib.h"
#include "include/vga.h"
#include "include/utils.h"

void print(const char* str) {
    terminal_writestring(str);
}

void put_char(char c) {
    terminal_putchar(c);
}

uint8_t get_char(void) {
    while (!key_pressed()) {}
    uint8_t key = read_key();
    return key;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

int strcmp(const char* str1, const char* str2) { }

char* strcpy(char* dest, const char* src) { }

char* strcat(char* dest, const char* src) { }

void* malloc(size_t size) { }

void free(void* ptr) { }

size_t read(int fd, void* buf, size_t count) { }

size_t write(int fd, const void* buf, size_t count) { }