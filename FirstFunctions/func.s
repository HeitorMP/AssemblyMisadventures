section .data                         	; Define a seção de variáveis
string db "This is fuckin assembly", 0	; Variável string com null terminator
numbers dd 10, 20, 30, 40, 50          	; Array de números

section .text                         	; Define a seção de código
global thisFunctionOnlyReturns42        ; Torna a função visível externamente, protótipo
global get_message                      
global get_numbers 						

thisFunctionOnlyReturns42:              ; Define o rótulo da função
    mov rax, 42                         ; Move o valor 42 para o registrador RAX (valor de retorno)
    ret                                 ; Retorno da função

get_message:                            ; Define uma função que retorna a string
    mov rax, string                     ; Move o endereço da variável string para rax
    ret                                 ; Retorno da função

get_numbers:                            ; Define uma função que retorna a string
    mov rax, numbers                  ; Move o endereço da variável(array) numbers para rax
    ret        							; Retorno da função