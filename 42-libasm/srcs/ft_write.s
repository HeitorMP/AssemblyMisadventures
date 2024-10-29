
;	ssize_t		ft_write(int fd, const void *buf, size_t count);
;	rdi = fd
;	rsi = buf
;	rdx = count

section .text
    global ft_write

ft_write:

    mov rax, 1                          ; syscall write
    syscall                             ; params already in order, calling syscall

    mov rax, rdx                        ; moving size to return
    ret
