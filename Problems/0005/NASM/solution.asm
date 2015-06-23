    section .projecteuler
    global project_euler_nasm_solution

project_euler_nasm_solution:
    mov rsi, 1
    mov rcx, 2
floop:
    cmp rcx, 20
    jg floopend
    mov rax, rsi
    xor rdx, rdx
    div rcx
    cmp rdx, 0
    jne floop_reset
floop_continue:
    inc rcx
    jmp floop
floop_reset:
    mov rcx, 2
    inc rsi
    jmp floop
floopend:
    mov rax, rsi
    ret
