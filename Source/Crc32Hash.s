global Crc32Hash_asm
section .text

Crc32Hash_asm:
    xor rax, rax
    crc32 rax, qword [rdi]
    crc32 rax, qword [rdi+8]
    crc32 rax, qword [rdi+16]
    crc32 rax, qword [rdi+24]
    ret
