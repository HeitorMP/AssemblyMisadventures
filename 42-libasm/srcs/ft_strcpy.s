section .text

global ft_strcpy

ft_strcpy:
	test rsi, rsi						; Test if parameter 2 is null;
	jz .handle_error					; Jump to handle error

	mov rax, rdi						; save rdi original pointer in rax(return);

.loop:
	mov al, byte [rsi]       			; save 1 byte from rsi into al
    mov byte [rdi], al       			; save 1 byte from al into rdi (swap using al as aux) - al is the 8 bits register inside rax
    
    test al, al              			; test if al byte is the null terminator
    je .end_loop              			; if al == 0 goto to end_loop

    inc rsi                  			; rsi++
    inc rdi                  			; rdi++
    jmp .loop            				; loop

.end_loop:
    mov rax, rdi
	ret

.handle_error:
	xor rax, rax                 		; if src is null return 0;
    ret