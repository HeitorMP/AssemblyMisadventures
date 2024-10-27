section .data                           ; Define the data section
string db "This is f..... assembly", 0  ; String variable with null terminator
numbers dd 10, 20, 30, 40, 50           ; Array of numbers

section .text                         	; Define the code section
global thisFunctionOnlyReturns42        ; Makes the function visible externally, prototype
global get_message                      
global get_numbers

thisFunctionOnlyReturns42:              ; Define the label for the function
    mov rax, 42                         ; Move the value 42 into the RAX register (return value)
    ret                                 ; Return from the function

get_message:                            ; Define a function that returns the string
    mov rax, string                     ; Move the address of the string variable into RAX
    ret                                 ; Return from the function

get_numbers:                            ; Define a function that returns the array
    mov rax, numbers                    ; Move the address of the numbers array into RAX
    ret                                 ; Return from the function