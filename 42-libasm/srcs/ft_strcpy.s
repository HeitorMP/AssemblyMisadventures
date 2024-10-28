
;	char		*ft_strcpy(char *dest, const char *src);
;   rdi = dest
;   rsi = src

section .text

global ft_strcpy

ft_strcpy:
	test rsi, rsi						; Test if parameter 1 is null;
	jz .handle_error					; Jump to handle error

	mov rax, rdi						; save rdi original pointer in rax(return);

.loop:
	mov al, byte [rsi]       			; Carrega um byte da origem (rsi) em al
    mov byte [rdi], al       			; Armazena o byte atual no destino (rdi)
    
    test al, al              			; Verifica se o byte atual é o terminador nulo
    je .end_loop              			; Se al == 0, fim da string; sai do loop

    inc rsi                  			; Avança para o próximo byte na origem
    inc rdi                  			; Avança para o próximo byte no destino
    jmp .loop            				; Repete o loop

.end_loop:
	mov byte [rdi], 0					;null terminator
	ret

.handle_error:
	xor rax, rax                 		; Se o ponteiro de origem for nulo, retorna 0
    ret