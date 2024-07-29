# NASM (Netwide Assembler)

NASM (Netwide Assembler) is an assembler for the x86 and x86-64 architectures. It is used to write programs in assembly language, which is a low-level programming language that provides a way to write instructions that a computer's CPU can execute directly.

Key points about NASM programming:

### Purpose and Use
- NASM is used to convert assembly language code into machine code, which can then be executed by the computer's processor.
- It supports multiple output formats, including flat binaries, COFF, ELF, Mach-O, and more, making it versatile for various operating systems and environments.

### Syntax and Structure
- NASM uses a straightforward and readable syntax. Assembly programs written in NASM typically have a .asm file extension.
- The basic structure of a NASM program includes sections for data (.data), binary data (.bss), and code (.text).

- Example Program : A simple "Hello, World!" program in NASM 
```NASM
    section .data
      hello db 'Hello, World!',0  ; The string to print

    section .text
      global _start               ; The entry point for the program

    _start:
      ; Write the string to stdout
      mov eax, 4                  ; sys_write
      mov ebx, 1                  ; file descriptor (stdout)
      mov ecx, hello              ; pointer to the string
      mov edx, 13                 ; number of bytes to write
      int 0x80                    ; call the kernel

      ; Exit the program
      mov eax, 1                  ; sys_exit
      xor ebx, ebx                ; status 0
      int 0x80                    ; call the kernel
```

- This example demonstrates basic system calls to write a string to standard output and exit the program.

### Assembly Process
- The process of assembling a NASM program involves writing the source code in a .asm file, assembling it with the NASM assembler to produce an object file, and linking it with a linker to create an executable.

Example commands

        nasm -f elf64 hello.asm       # Assemble the source file into an object file
        ld -o hello hello.o           # Link the object file to create an executable
        ./hello                       # Run the executable

- NASM provides a powerful and flexible way to write low-level programs for x86-based systems, allowing for direct control over hardware and efficient execution.
