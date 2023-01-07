#ifndef KERNEL_UTILS_H
#define KERNEL_UTILS_H

#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif // KERNEL_UTILS_H