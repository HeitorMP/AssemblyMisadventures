section .text

global ft_strcmp

ft_strcmp:
    xor rax, rax                  ; Clear rax for return value
    xor rbx, rbx                  ; Clear rbx

.loop:
    movzx eax, byte [rdi]         ; Load and zero-extend char from s1 into eax
    movzx ebx, byte [rsi]         ; Load and zero-extend char from s2 into ebx

    cmp eax, ebx                  ; Compare characters
    jne .end_loop                 ; If they are not equal, exit loop

    test eax, eax                 ; Check if we reached the end of s1 (NULL)
    jz .end_loop                  ; If end of s1, exit loop

    inc rdi                       ; Move to next char of s1
    inc rsi                       ; Move to next char of s2

    jmp .loop                     ; Repeat the loop

.end_loop:
    sub eax, ebx                  ; Compute s1 - s2 (eax - ebx)
    mov rax, rax                  ; Move result into rax for return

    ret                           ; Return
