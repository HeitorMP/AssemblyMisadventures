section .data                           ; Define the data section
string db "This is f..... assembly", 0  ; String variable with null terminator
numbers dd 10, 20, 30, 40, 50           ; Array of numbers

section .text                         	; Define the code section
global thisFunctionOnlyReturns42        ; Makes the function visible externally, prototype
global get_message                      
global get_numbers
global get_string_length
global exit_code
global print_string

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
    xor rax, rax                        ; 0 rax value

.get_string_length_loop:                ; this loop for strng length
    cmp byte [rdi + rax], 0             ; Compare rdi(byte position of string) + rax(index) with 0(null terminator)
    je .get_string_length_end_loop      ; je = jump if equal. If cpm = 0 break the loop
    inc rax                             ; if cmp != 0 rax++
    jmp .get_string_length_loop         ; loop

.get_string_length_end_loop:
    ret                                 ; Return from the function

exit_code:
    mov rax, 60                         ; Define rax with syscall 60(exit status code)
    mov rdi, 1                          ; rdi value = 1;
    syscall                             ; exit with the syscall 60 using rdi as value
    ret                                 ; never called becouse syscall

print_string:

    mov r8, rdi                         ; r8 now holds the pointer to the string
    mov r9, rsi                         ; r9 now holds lenght
    
    mov rax, 1                          ; rax to syscall write
    mov rdi, 1                          ; Set RDI to 1 (stdout file descriptor)

    mov rsi, r8                         ; rsi is now the pointer
    mov rdx, r9

    syscall                             ; Make the syscall to write the string
    ret                                 ; Return from the function