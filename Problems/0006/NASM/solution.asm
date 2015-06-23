    section .projecteuler
    global project_euler_nasm_solution

project_euler_nasm_solution:
    mov rsi, 100
    xor r10, r10
    xor r11, r11
    xor rdi, rdi
nloop:
    inc rdi
    cmp rdi, rsi
    jg nloopend
    mov rax, rdi
    mul rax
    add r10, rax
    add r11, rdi
    jmp nloop
nloopend:
    mov rax, r11
    mul rax
    sub rax, r10
    ret
