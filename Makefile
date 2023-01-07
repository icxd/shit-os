CP := cp
RM := rm -rf
MKDIR := mkdir -pv

SRC = src/$(wildcard *.c)
OBJ = $(SRC:.c=.o)

BIN = kernel
CFG = grub.cfg
ISO_PATH := iso
BOOT_PATH := $(ISO_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub

.PHONY: all
all: bootloader kernel # linker iso run
	@echo Completed

bootloader: boot.asm
	nasm -f elf32 boot.asm -o boot.o

kernel:
	gcc -m32 -c $(SRC) -o kernel.o

linker: linker.ld boot.o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o

iso: kernel
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o my-kernel.iso $(ISO_PATH)

run: my-kernel.iso
	qemu-system-x86_64 my-kernel.iso

.PHONY: clean
clean:
	$(RM) *.o src/*.o *.iso *.bin *.elf $(BIN) *iso
	