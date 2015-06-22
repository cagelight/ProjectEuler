    section .projecteuler
    global project_euler_nasm_solution

add2sum:
    add esi,ecx
    jmp floop_end

project_euler_nasm_solution:
    xor rsi, rsi
    xor ecx, ecx
    mov r10d, 3
    mov r11d, 5
    floop:
    inc ecx
    floop3:
    xor edx, edx
    mov eax, ecx
    div r10d
    cmp edx, 0
    je add2sum
    floop5:
    xor edx, edx
    mov eax, ecx
    div r11d
    cmp edx, 0
    je add2sum
    floop_end:
    cmp ecx, 999
    jne floop
    mov rax, rsi
    ret
