ifndef LLVM
$(error LLVM is not set. Export it first, e.g. export LLVM=/path/to/llvm/bin)
endif

ifndef RISCV
$(error RISCV is not set. Export it first, e.g. export RISCV=/path/to/riscv)
endif

CC      = $(LLVM)/clang
OBJDUMP = $(LLVM)/llvm-objdump

TARGET  = riscv64-unknown-elf
ARCH    = rv64gv_xdse0p1
ABI     = lp64d

COMMON_FLAGS = \
    --target=$(TARGET) \
    --sysroot=$(RISCV)/riscv64-unknown-elf \
    --gcc-toolchain=$(RISCV) \
    -march=$(ARCH) \
    -mabi=$(ABI) \
    -menable-experimental-extensions \
    -I$(RISCV)/include \
    -O3

all: test.o test.s test.elf test.dump

# Object file
test.o: main.c
	$(CC) $(COMMON_FLAGS) -c $< -o $@

# Executable ELF
test.elf: main.c
	$(CC) $(COMMON_FLAGS) $< -o $@

# Compiler-generated assembly
test.s: main.c
	$(CC) $(COMMON_FLAGS) -S $< -o $@

# Disassembly
test.dump: test.elf
	$(OBJDUMP) -d $< > $@

clean:
	rm -f test.o test.s test.elf test.dump