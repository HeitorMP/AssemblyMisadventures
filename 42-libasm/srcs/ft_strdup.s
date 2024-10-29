
section .text
	global ft_strdup
	extern ft_strlen
	extern malloc

ft_strdup:

	call ft_strlen						; calling strlen rdi, results goes into rax

	inc rax								; rax now has the len , inc rax for the null terminator
    call malloc			                ; call malloc; result (pointer) is in rax, but save the len in rdi

	test rax, rax						; testing malloc return
	jz allocation_failed				; if zero go to error handler

    mov rsi, rdi              			; rsi = pointer to the original string
    mov rdi, rax              			; rdi = pointer to the new string

copy_loop:
    mov al, [rsi]             			; load current character from original string
    mov [rdi], al             			; copy character to new string
    inc rsi                   			; move to next character in original string
    inc rdi                   			; move to next character in new string
    test al, al               			; check for null terminator
    jnz copy_loop             			; repeat until we hit the null terminator

    ret      			                ; return pointer to the duplicated string

allocation_failed:
	mov rax, 0							; returning null ir error
	ret