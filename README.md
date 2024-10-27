# Assembly Misadventures
Welcome to my personal laboratory for exploring the fascinating world of Assembly language!


## Some random notes
| Name | Notes | Type |
|------|-------|------|
| rax  | Values are returned from functions in this register. | scratch |
| rcx  | Typical scratch register. Some instructions also use it as a counter. | scratch |
| rdx  | Scratch register. | scratch |
| rbx  | Preserved register: don't use it without saving it! | preserved |
| rsp  | The stack pointer. Points to the top of the stack (details coming soon!) | preserved |
| rbp  | Preserved register. Sometimes used to store the old value of the stack pointer, or the "base". | preserved |
| rsi  | Scratch register used to pass function argument #2 in 64-bit Linux. In 64-bit Windows, a preserved register. | scratch |
| rdi  | Scratch register and function argument #1 in 64-bit Linux. In 64-bit Windows, a preserved register. | scratch |
| r8   | Scratch register. These were added in 64-bit mode, so they have numbers, not names. | scratch |
| r9   | Scratch register. | scratch |
| r10  | Scratch register. | scratch |
| r11  | Scratch register. | scratch |
| r12  | Preserved register. You can use it, but you need to save and restore it. | preserved |
| r13  | Preserved register. | preserved |
| r14  | Preserved register. | preserved |
| r15  | Preserved register. | preserved |


```
A 64 bit linux machine passes function parameters in rdi, rsi, rdx, rcx, r8, and r9.  
Any additional parameters get pushed on the stack.  OS X in 64 bit uses the same parameter scheme.
```

| C/C++ Datatype | Bits | Bytes | Register | Access Memory | Allocate Memory |
|----------------|------|-------|----------|---------------|-----------------|
| char           | 8    | 1     | al       | BYTE [ptr]    | db              |
| short          | 16   | 2     | ax       | WORD [ptr]    | dw              |
| int            | 32   | 4     | eax      | DWORD [ptr]   | dd              |
| long           | 64   | 8     | rax      | QWORD [ptr]   | dq              |
