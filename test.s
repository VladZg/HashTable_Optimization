	.file	"HashFunctions.cpp"
	.intel_syntax noprefix
	.text
	.section	.rodata
	.align 4
	.type	_ZL20HashTableListAvgSize, @object
	.size	_ZL20HashTableListAvgSize, 4
_ZL20HashTableListAvgSize:
	.long	1069547520
	.text
	.globl	_Z9ConstHashPKc
	.type	_Z9ConstHashPKc, @function
_Z9ConstHashPKc:
.LFB15:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], rdi
	mov	eax, 500
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	_Z9ConstHashPKc, .-_Z9ConstHashPKc
	.globl	_Z7LenHashPKc
	.type	_Z7LenHashPKc, @function
_Z7LenHashPKc:
.LFB16:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	strlen@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	_Z7LenHashPKc, .-_Z7LenHashPKc
	.globl	_Z13FirstSymbHashPKc
	.type	_Z13FirstSymbHashPKc, @function
_Z13FirstSymbHashPKc:
.LFB17:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], rdi
	mov	rax, QWORD PTR -8[rbp]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	_Z13FirstSymbHashPKc, .-_Z13FirstSymbHashPKc
	.globl	_Z7SumHashPKc
	.type	_Z7SumHashPKc, @function
_Z7SumHashPKc:
.LFB18:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -16[rbp], 0
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	DWORD PTR -12[rbp], 0
	jmp	.L8
.L9:
	mov	eax, DWORD PTR -12[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	add	DWORD PTR -16[rbp], eax
	add	DWORD PTR -12[rbp], 1
.L8:
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	cmp	QWORD PTR -8[rbp], rax
	ja	.L9
	mov	eax, DWORD PTR -16[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	_Z7SumHashPKc, .-_Z7SumHashPKc
	.type	_ZL3ROLii, @function
_ZL3ROLii:
.LFB19:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	DWORD PTR -8[rbp], esi
	mov	eax, DWORD PTR -8[rbp]
	mov	edx, DWORD PTR -4[rbp]
	mov	esi, edx
	mov	ecx, eax
	sal	esi, cl
	mov	eax, 32
	sub	eax, DWORD PTR -8[rbp]
	mov	edx, DWORD PTR -4[rbp]
	mov	ecx, eax
	sar	edx, cl
	mov	eax, edx
	or	eax, esi
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	_ZL3ROLii, .-_ZL3ROLii
	.globl	_Z7RolHashPKc
	.type	_Z7RolHashPKc, @function
_Z7RolHashPKc:
.LFB20:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -16[rbp], 0
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	DWORD PTR -12[rbp], 0
	jmp	.L14
.L15:
	mov	eax, DWORD PTR -16[rbp]
	mov	esi, 1
	mov	edi, eax
	call	_ZL3ROLii
	mov	edx, eax
	mov	eax, DWORD PTR -12[rbp]
	movsx	rcx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rcx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	xor	eax, edx
	mov	DWORD PTR -16[rbp], eax
	add	DWORD PTR -12[rbp], 1
.L14:
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	cmp	QWORD PTR -8[rbp], rax
	ja	.L15
	mov	eax, DWORD PTR -16[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	_Z7RolHashPKc, .-_Z7RolHashPKc
	.type	_ZL3RORii, @function
_ZL3RORii:
.LFB21:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	DWORD PTR -8[rbp], esi
	mov	eax, DWORD PTR -8[rbp]
	mov	edx, DWORD PTR -4[rbp]
	mov	esi, edx
	mov	ecx, eax
	sar	esi, cl
	mov	eax, 32
	sub	eax, DWORD PTR -8[rbp]
	mov	edx, DWORD PTR -4[rbp]
	mov	ecx, eax
	sal	edx, cl
	mov	eax, edx
	or	eax, esi
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	_ZL3RORii, .-_ZL3RORii
	.globl	_Z7RorHashPKc
	.type	_Z7RorHashPKc, @function
_Z7RorHashPKc:
.LFB22:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -16[rbp], 0
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	DWORD PTR -12[rbp], 0
	jmp	.L20
.L21:
	mov	eax, DWORD PTR -16[rbp]
	mov	esi, 1
	mov	edi, eax
	call	_ZL3RORii
	mov	edx, eax
	mov	eax, DWORD PTR -12[rbp]
	movsx	rcx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rcx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	xor	eax, edx
	mov	DWORD PTR -16[rbp], eax
	add	DWORD PTR -12[rbp], 1
.L20:
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	cmp	QWORD PTR -8[rbp], rax
	ja	.L21
	mov	eax, DWORD PTR -16[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	_Z7RorHashPKc, .-_Z7RorHashPKc
	.section	.rodata
	.align 32
	.type	_ZL6sTable, @object
	.size	_ZL6sTable, 256
_ZL6sTable:
	.string	"\243\327\t\203\370H\366\364\263!\025x\231\261\257\371\347-M\212\316L\312.R\225\331\036N8D(\n\337\002\240\027\361`h\022\267z\303\351\372=S\226\204k\272\362c\232\031|\256\345\365\367\026j\2429\266{\017\301\223\201\033\356\264\032\352\320\221/\270U\271\332\205?A\277\340ZX\200_f\013\330\2205\325\300\2473\006eiE"
	.ascii	"\224Vm\230\233v\227\374\262\302\260\376\333 \341\353\326\344"
	.ascii	"\335GJ\035B\355\236nI<\315C'\322\007\324\336\307g\030\211\313"
	.ascii	"0\037\215\306\217\252\310t\334\311]\\1\244p\210a,\237\r+\207"
	.ascii	"P\202Td&}\003@4K\034s\321\304\375;\314\373\177\253\346>[\245"
	.ascii	"\255\004#\234\024Q\"\360)yq~\377\214\016\342\f\357\274ruo7\241"
	.ascii	"\354\323\216b\213\206\020\350\bw\021\276\222O$\30526\235\317"
	.ascii	"\363\246\273\254^l\251\023W%\265\343\275\250:\001\005Y*F"
	.text
	.globl	_Z6MyHashPKc
	.type	_Z6MyHashPKc, @function
_Z6MyHashPKc:
.LFB23:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -16[rbp], 0
	mov	DWORD PTR -8[rbp], 1723969
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	DWORD PTR -4[rbp], eax
	mov	DWORD PTR -12[rbp], 0
	jmp	.L24
.L25:
	mov	eax, DWORD PTR -12[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	edx, al
	mov	eax, DWORD PTR -12[rbp]
	add	eax, edx
	movzx	eax, al
	cdqe
	lea	rdx, _ZL6sTable[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	movzx	eax, al
	add	DWORD PTR -16[rbp], eax
	mov	eax, DWORD PTR -16[rbp]
	mov	esi, 2
	mov	edi, eax
	call	_ZL3RORii
	mov	DWORD PTR -16[rbp], eax
	mov	edx, DWORD PTR -16[rbp]
	mov	eax, DWORD PTR -12[rbp]
	add	edx, eax
	mov	eax, DWORD PTR -8[rbp]
	imul	eax, edx
	mov	DWORD PTR -16[rbp], eax
	add	DWORD PTR -12[rbp], 1
.L24:
	mov	eax, DWORD PTR -12[rbp]
	cmp	eax, DWORD PTR -4[rbp]
	jl	.L25
	mov	edx, DWORD PTR -16[rbp]
	mov	eax, DWORD PTR -4[rbp]
	add	eax, edx
	imul	eax, DWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE23:
	.size	_Z6MyHashPKc, .-_Z6MyHashPKc
	.globl	_Z7GnuHashPKc
	.type	_Z7GnuHashPKc, @function
_Z7GnuHashPKc:
.LFB24:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -12[rbp], 5381
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	DWORD PTR -4[rbp], eax
	mov	DWORD PTR -8[rbp], 0
	jmp	.L28
.L29:
	mov	eax, DWORD PTR -12[rbp]
	mov	edx, eax
	sal	edx, 5
	lea	ecx, [rdx+rax]
	mov	eax, DWORD PTR -8[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	add	eax, ecx
	mov	DWORD PTR -12[rbp], eax
	add	DWORD PTR -8[rbp], 1
.L28:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -4[rbp]
	jl	.L29
	mov	eax, DWORD PTR -12[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE24:
	.size	_Z7GnuHashPKc, .-_Z7GnuHashPKc
	.globl	_Z11GnuHash_asmPKc
	.type	_Z11GnuHash_asmPKc, @function
_Z11GnuHash_asmPKc:
.LFB25:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -4[rbp], 0
#APP
# 121 "./Source/HashFunctions.cpp" 1
	.intel_syntax noprefix
   push r8
   push r9
   xor rax, rax
   mov r8d, 5381
loop_start:
   mov al, [rdi]
   cmp eax, 0
   je loop_end
   mov r9d, r8d
   shl r8d, 5
   add r8d, r9d
   add r8d, eax
   inc rdi
   jmp loop_start
loop_end:
   mov eax, r8d
   pop r9
   pop r8
.att_syntax

# 0 "" 2
#NO_APP
	mov	DWORD PTR -4[rbp], eax
	mov	eax, DWORD PTR -4[rbp]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE25:
	.size	_Z11GnuHash_asmPKc, .-_Z11GnuHash_asmPKc
	.globl	_Z9Crc32HashPKc
	.type	_Z9Crc32HashPKc, @function
_Z9Crc32HashPKc:
.LFB26:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -4[rbp], -1
	mov	eax, DWORD PTR -4[rbp]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE26:
	.size	_Z9Crc32HashPKc, .-_Z9Crc32HashPKc
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	eax, 1
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
