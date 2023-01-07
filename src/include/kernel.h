#ifndef KERNEL_H
#define KERNEL_H

#include "vga.h"
#include "keyboard.h"

#ifdef __cplusplus
extern "C" { /* Use C linkage for kernel_main. */
#endif

bool restart();
void shutdown();
void kernel_main(void);

void blue_screen(const char* errorcode, const char* errormessage) {
    terminal_setcolor(VGA_COLOR_BACKGROUND(VGA_COLOR_BLUE) | VGA_COLOR_FOREGROUND(VGA_COLOR_WHITE));
    terminal_writestring("A problem has been detected and the system has been shut down to prevent");
    terminal_writestring("damage to your computer.");
    terminal_writestring("");
    uint32_t i = 0;
    terminal_writestring_without_newline(errorcode);
    i += strlen(errorcode);
    terminal_writestring_without_newline(": ");
    i += 2;
    terminal_writestring_without_newline(errormessage);
    i += strlen(errormessage);
    for (; i < VGA_WIDTH; i++)
        terminal_putchar(' ');
    terminal_writestring("");
    terminal_writestring("If this is the first time you've seen this Stop error screen, restart");
    terminal_writestring("your computer. If this screen appears again, follow these steps:");
    terminal_writestring("");
    terminal_writestring("Check to make sure any new hardware or software is properly installed.");
    terminal_writestring("If this is a new installation, ask your hardware or software");
    terminal_writestring("manufacturer for any Windows updates you might need.");
    terminal_writestring("");
    terminal_writestring("If problems continue, disable or remove any newly installed hardware");
    terminal_writestring("or software. Disable BIOS memory options such as caching or shadowing.");
    terminal_writestring("If you need to use Safe Mode to remove or disable components, restart");
    terminal_writestring("your computer, press F8 to select Advanced Startup Options, and then");
    terminal_writestring("select Safe Mode.");
    terminal_writestring("");
    terminal_writestring("Technical Information:");
    terminal_writestring("");
    terminal_writestring("*** STOP: 0x0000007B (0xF78D2524, 0xC0000034, 0x00000000, 0x00000000)");

    for (unsigned int i = 0; i < VGA_WIDTH * VGA_HEIGHT - vga_index; i++) {
        terminal_putchar(' ');
    }
    while (1) {
        while (!key_pressed()) {}
        uint8_t key = read_key();
        if (key == 0x3B) {
            if (restart() != 0)
                terminal_writestring("failed to restart.");
            return;
        } else if (key == 0x3C) {
            shutdown();
            return;
        }
    }
}

#ifdef __cplusplus
}
#endif

#endif /* KERNEL_H */