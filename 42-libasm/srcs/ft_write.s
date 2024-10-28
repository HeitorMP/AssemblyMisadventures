
;	ssize_t		ft_write(int fd, const void *buf, size_t count);
;	rdi = fd
;	rsi = buf
;	rdx = count

sextion .text

ft_write:

    mov r8, rdi                         ; r8 now holds the pointer to the string
    mov r9, rsi                         ; r9 now holds lenght
    
    mov rax, 1                          ; rax to syscall write

    mov rsi, r8                         ; rsi is now the pointer
    mov rdx, r9

    syscall                             ; Make the syscall to write the string

	mov rax, rdx
    ret                        