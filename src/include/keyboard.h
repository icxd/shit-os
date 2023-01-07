#ifndef KERNEL_KEYBOARD_H
#define KERNEL_KEYBOARD_H

#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif

bool key_pressed();
uint8_t read_key();
char convert_key(uint8_t key);

#ifdef __cplusplus
}
#endif

#endif // KERNEL_KEYBOARD_H