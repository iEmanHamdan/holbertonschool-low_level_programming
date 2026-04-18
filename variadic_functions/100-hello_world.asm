section .text
    global main

main:
    ; syscall: write(1, message, 13)
    mov rax, 1          ; system call for write
    mov rdi, 1          ; file descriptor 1 is stdout
    mov rsi, message    ; address of string to output
    mov rdx, 13         ; number of bytes
    syscall             ; invoke operating system to do the write

    ; syscall: exit(0)
    mov rax, 60         ; system call for exit
    xor rdi, rdi        ; exit code 0
    syscall             ; invoke operating system to exit

section .data
    message db "Hello, World", 10 ; 10 is the ASCII for new line

