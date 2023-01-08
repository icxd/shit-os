#include "include/fs.h"

void create_file(FileSystem *fs, const char *path, const char *contents) {
    if (fs->num_files >= MAX_FILES) {
        return;
    }
    File *file = &fs->files[fs->num_files++];
    file->data = strdup(contents);
    file->size = strlen(contents);
    file->path = strdup(path);
}

const char* read_file(FileSystem *fs, const char *path) {
    for (int i = 0; i < fs->num_files; i++) {
        File *file = &fs->files[i];
        if (strcmp(file->path, path) == 0) {
            return file->data;
        }
    }
    blue_screen("FILE_NOT_FOUND", "Failed to read file");
    return NULL;
}

void delete_file(FileSystem *fs, const char *path) {
    for (int i = 0; i < fs->num_files; i++) {
        File *file = &fs->files[i];
        if (strcmp(file->path, path) == 0) {
            free(file->data);
            file->data = NULL;
            file->size = 0;
            strcpy(file->path, "");
            return;
        }
    }
}
