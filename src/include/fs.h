#ifndef KERNEL_FS_H
#define KERNEL_FS_H

#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif 

#define MAX_FILES 128

typedef struct {
    char *data;
    const char *path;
    size_t size;
} File;

typedef struct {
    File files[MAX_FILES];
    size_t num_files;
} FileSystem;

void create_file(FileSystem *fs, const char *path, const char *contents);
const char* read_file(FileSystem *fs, const char *path);
void delete_file(FileSystem *fs, const char *path);

#ifdef __cplusplus
}
#endif

#endif /* KERNEL_FS_H */