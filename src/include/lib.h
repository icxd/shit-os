#ifndef KERNEL_LIB_H
#define KERNEL_LIB_H

#define NULL ((void*) 0)

typedef unsigned size_t;
typedef unsigned ptrdiff_t;
typedef unsigned char bool;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

#ifdef __cplusplus
extern "C" { /* Use C linkage for kernel_main. */
#endif

void print(const char* str);
void put_char(char c);
char get_char();

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
char* strcpy(char* dest, const char* src);
char* strcat(char* dest, const char* src);

void* malloc(size_t size);
void free(void* ptr);

void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* ptr, int value, size_t num);

size_t read(int fd, void* buf, size_t count);
size_t write(int fd, const void* buf, size_t count);

#ifdef __cplusplus
}
#endif

#endif /* KERNEL_LIB_H */