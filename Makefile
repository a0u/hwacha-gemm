CC := riscv64-unknown-elf-gcc
OBJDUMP := riscv64-unknown-elf-objdump

CFLAGS := -march=rv64gcxhwacha -O2 -std=c99 -Wall -specs=htif_nano.specs

.PHONY: all
all: sgemm.dump

.PRECIOUS: %.riscv
%.riscv: $(wildcard *.h *.c *.S)
	$(CC) $(CFLAGS) -o $@ $^

%.dump: %.riscv
	$(OBJDUMP) -d $< > $@

.PHONY: clean
clean:
	rm -f -- *.riscv *.dump

.SUFFIXES: # Disable built-in suffix rules
