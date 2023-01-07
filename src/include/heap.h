#ifndef KERNEL_HEAP_H
#define KERNEL_HEAP_H

#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HEAP_SIZE 1024

void *heap_alloc(size_t size);
void heap_free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif // KERNEL_HEAP_H