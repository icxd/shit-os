#include "include/lib.h"
#include "include/vga.h"
#include "include/utils.h"
#include "include/heap.h"

void print(const char* str) {
    terminal_writestring(str);
}

void put_char(char c) {
    terminal_putchar(c);
}

char get_char(void) {
    while (!key_pressed()) {}
    uint8_t key = read_key();
    char c = convert_key(key);
    if (c == 0)
        return NULL;
    return c;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

int strcmp(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    if (len1 != len2)
        return 1;
    for (size_t i = 0; i < len1; i++) {
        if (str1[i] != str2[i])
            return 1;
    }
    return 0;
}

char* strcpy(char* dest, const char* src) {
    size_t len = strlen(src);
    for (size_t i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

char* strcat(char* dest, const char* src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    for (size_t i = 0; i < src_len; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + src_len] = '\0';
    return dest;
}

char* strdup(const char* str) {
    size_t len = strlen(str);
    char* new_str = (char*) malloc(len + 1);
    strcpy(new_str, str);
    return new_str;
}

void* malloc(size_t size) {
    return heap_alloc(size);
}

void free(void* ptr) { heap_free(ptr); }

void* memcpy(void* dest, const void* src, size_t n) {
    char* d = (char*) dest;
    const char* s = (const char*) src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

void* memset(void* ptr, int value, size_t num) {
    char* p = (char*) ptr;
    for (size_t i = 0; i < num; i++) {
        p[i] = value;
    }
    return ptr;
}

size_t read(int fd, void* buf, size_t count) { }

size_t write(int fd, const void* buf, size_t count) { }