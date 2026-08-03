# RISC-V Data Stream Extension (DSE)

This repository contains the specification, assembler, and test programs for the **RISC-V Data Stream Extension (DSE)**.

## Repository Structure

```text
.
├── RISC-V Data Stream Extension.adoc   # Extension specification
├── buildLLVM.sh                        # Build LLVM with DSE support
├── setupLLVM.sh                        # Environment setup script
├── generate_patch.sh                   # Generate a Git patch of local changes
├── test/
│   ├── branch/                         # Branch instruction tests
│   └── streams/                        # Stream instruction tests
└── patch/                              # Generated patches (optional)
```

## Prerequisite: Install a RISC-V GNU bare-metal toolchain (riscv64-unknown-elf).

Although this project uses LLVM/Clang as the compiler, Clang relies on the GNU toolchain to provide the target sysroot, including the C standard library (newlib), startup files (crt*.o), and runtime libraries (libgcc). These components are required to build and link bare-metal RISC-V executables.

## Building LLVM


Clone LLVM and apply patchs:

```bash
bash setupLLVM.sh
```

Build the modified LLVM toolchain by running:

```bash
bash buildLLVM.sh
```

## Running the Tests

Export the required environment variables manually:

```bash
export LLVM=/path/to/llvm/bin
export RISCV=/path/to/riscv
```
Each test directory contains its own `Makefile`.

For example:

```bash
cd test/streams
make
```

or

```bash
cd test/branch
make
```


## Documentation

The extension specification is provided in:

```text
RISC-V Data Stream Extension.adoc
```