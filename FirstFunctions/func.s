section .data                           ; Define the data section
string db "This is f..... assembly", 0  ; String variable with null terminator
numbers dd 10, 20, 30, 40, 50           ; Array of numbers

section .text                         	; Define the code section
global thisFunctionOnlyReturns42        ; Makes the function visible externally, prototype
global get_message                      
global get_numbers
global get_string_length 

thisFunctionOnlyReturns42:              ; Define the label for the function
    mov rax, 42                         ; Move the value 42 into the RAX register (return value)
    ret                                 ; Return from the function

get_message:                            ; Define a function that returns the string
    mov rax, string                     ; Move the address of the string variable into RAX
    ret                                 ; Return from the function

get_numbers:                            ; Define a function that returns the array
    mov rax, numbers                    ; Move the address of the numbers array into RAX
    ret                                 ; Return from the function

get_string_length:
    mov rdi, string                     ; Move string to rdi
    xor rax, rax                        ; 0 rax value

.get_string_length_loop:                ; this loop for strng length
    cmp byte [rdi + rax], 0             ; Compare rdi(byte position of string) + rax(index) with 0(null terminator)
    je .get_string_length_end_loop      ; je = jump if equal. If cpm = 0 break the loop
    inc rax                             ; if cmp != 0 rax++
    jmp .get_string_length_loop         ; loop

.get_string_length_end_loop:
    ret                                 ; Return from the function

