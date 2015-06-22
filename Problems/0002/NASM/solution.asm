    section .projecteuler
    global project_euler_nasm_solution

addsumA:
    add rax, r10
    jmp fibloopB

addsumB:
    add rax, r11
    jmp fibloopA

project_euler_nasm_solution:
    xor rax, rax
    mov r10, 1
    mov r11, 1
fibloopA:
    add r10, r11
    cmp r10, 4000000
    jg fibend
    mov rcx, 1
    and rcx, r10
    jz addsumA
fibloopB:
    add r11, r10
    cmp r11, 4000000
    jg fibend
    mov rcx, 1
    and rcx, r11
    jz addsumB
    jmp fibloopA
fibend:
    ret
