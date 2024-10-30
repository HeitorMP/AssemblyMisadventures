section .text
    global ft_strdup
    extern ft_strlen
    extern malloc

ft_strdup:
    push rbp                            ; Salva o valor de rbp na pilha
    mov rbp, rsp                        ; Estabelece o quadro da pilha

    push rdi                            ; Salva o ponteiro original (s) na pilha
    call ft_strlen                      ; Chama ft_strlen para obter o comprimento da string
    inc rax                             ; Incrementa rax para incluir o terminador nulo
    
    mov rdi, rax                        ; Prepara o argumento para malloc
    call malloc WRT ..plt               ; Chama malloc

    test rax, rax                       ; Verifica se malloc retornou NULL
    jz allocation_failed                 ; Se for NULL, pula para alocação falhou

    pop rsi                             ; Restaura o ponteiro original para rsi
    mov rdi, rax                        ; RDI agora contém o ponteiro para a nova string
    xor rcx, rcx

copy_loop:
    mov al, byte [rsi+rcx]              ; Carrega o caractere atual da string original
    mov byte [rdi+rcx], al              ; Copia o caractere para a nova string
    test al, al                         ; Verifica se é o terminador nulo
    jz end_copy                         ; Se for nulo, pula para o fim
    inc rcx                             ; Avança para o próximo caractere da nova string
    jmp copy_loop                       ; Repete o loop

end_copy:
    mov rsp, rbp                        ; Restaura o ponteiro da pilha
    pop rbp                             ; Restaura o rbp original
    mov rax, rdi
    ret
    
allocation_failed:
    mov rax, 0                          ; Retorna NULL em caso de falha
    leave                               ; Restaura o quadro da pilha e retorna
    ret
