#include "include/heap.h"

static char heap[HEAP_SIZE];
static size_t heap_pos = 0;

void* heap_alloc(size_t size) {
    if (heap_pos + size > HEAP_SIZE)
        return NULL;
    void* ptr = &heap[heap_pos];
    heap_pos += size;
    return ptr;
}

void heap_free(void* ptr) {
    if (ptr == NULL)
        return;
    size_t size = heap_pos - ((size_t)ptr - (size_t)heap);
    heap_pos -= size;
}