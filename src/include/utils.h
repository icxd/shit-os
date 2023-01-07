#ifndef KERNEL_UTILS_H
#define KERNEL_UTILS_H

#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif

bool key_pressed();
uint8_t read_key();
char convert_key(uint8_t key);

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif // KERNEL_UTILS_H