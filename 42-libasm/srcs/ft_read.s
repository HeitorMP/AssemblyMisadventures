
;   ssize_t read(int fd, void *buf, size_t count);
;	rdi = fd
;	rsi = buf
;	rdx = count

section .text
    global ft_read

ft_read:

    mov rax, 0                          ; syscall write
    syscall                             ; params already in order, calling syscall

    ret
