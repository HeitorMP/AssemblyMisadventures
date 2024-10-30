BITS 64


; ft_list_push_front(t_list **begin_list, void *data)
; rdi begin
; rsi new element
section .text
    global ft_list_push_front

ft_list_push_front:

    mov rax, [rdi]              ; save the value of in rax
    mov [rsi + 8], rax          ; saving rax in next of new element

    mov [rdi], rsi              ; begin now point to new element

    ret