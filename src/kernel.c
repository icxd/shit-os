#include "include/kernel.h"
#include "include/lib.h"
#include "include/driver.h"
#include "include/utils.h"
#include "include/keyboard.h"
#include "include/fs.h"

bool restart() {
    uint8_t status = inb(0x64);
    if (status & 0x02)
        return 1;
    outb(0x64, 0xFE);
    return 0;
}

void shutdown() {
    outb(0x64, 0xFE);
}

void kernel_main(void) {
    terminal_initialize();

    /*
    void* smash = malloc(696969);
    if (smash == NULL) {
        blue_screen("SEGFAULT", "Failed to allocate memory");
        return;
    }
    */

    // Initialize the filesystem
    FileSystem fs = {0};
    create_file(&fs, "/hello.txt", "Hello, world!");
    create_file(&fs, "/test.txt", "This is a test file.");

    // Print the contents of the files
    const char* hello = read_file(&fs, "/hello.txt");
    const char* test = read_file(&fs, "/test.txt");
    terminal_writestring(hello);
    terminal_writestring(test);

    // Delete the test file
    delete_file(&fs, "/test.txt");

    // Print the contents of the files again
    hello = read_file(&fs, "/hello.txt");
    test = read_file(&fs, "/test.txt");
    
    terminal_writestring(hello);
    terminal_writestring(test);

    return;
}
