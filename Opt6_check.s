	.file	"HashTable.cpp"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"void HashTableVerify(const HashTable*)"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"./Source/HashTable.cpp"
.LC2:
	.string	"hash_table->hash_function"
	.text
	.p2align 4
	.type	_ZL15HashTableVerifyPK9HashTable.part.0, @function
_ZL15HashTableVerifyPK9HashTable.part.0:
.LFB5563:
	.cfi_startproc
	push	rax
	.cfi_def_cfa_offset 16
	pop	rax
	.cfi_def_cfa_offset 8
	lea	rcx, .LC0[rip]
	mov	edx, 13
	lea	rsi, .LC1[rip]
	lea	rdi, .LC2[rip]
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	call	__assert_fail@PLT
	.cfi_endproc
.LFE5563:
	.size	_ZL15HashTableVerifyPK9HashTable.part.0, .-_ZL15HashTableVerifyPK9HashTable.part.0
	.section	.rodata.str1.8
	.align 8
.LC3:
	.string	"int HashTableCtor(HashTable*, size_t, int (*)(const char*))"
	.section	.rodata.str1.1
.LC4:
	.string	"hash_table"
.LC5:
	.string	"hash_function"
.LC6:
	.string	"hash_table->lists"
	.text
	.p2align 4
	.globl	_Z13HashTableCtorP9HashTablemPFiPKcE
	.type	_Z13HashTableCtorP9HashTablemPFiPKcE, @function
_Z13HashTableCtorP9HashTablemPFiPKcE:
.LFB5556:
	.cfi_startproc
	endbr64
	push	r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	test	rdi, rdi
	je	.L14
	test	rdx, rdx
	je	.L15
	mov	QWORD PTR 8[rdi], rsi
	mov	r12, rsi
	mov	rbp, rdi
	mov	esi, 56
	mov	QWORD PTR [rdi], 0
	mov	QWORD PTR 24[rdi], rdx
	mov	rdi, r12
	call	calloc@PLT
	mov	QWORD PTR 16[rbp], rax
	mov	rbx, rax
	test	rax, rax
	je	.L7
	xor	ebp, ebp
	test	r12, r12
	je	.L9
	.p2align 4,,10
	.p2align 3
.L10:
	mov	rdi, rbx
	add	rbp, 1
	add	rbx, 56
	call	_Z8ListCtorP4List@PLT
	cmp	r12, rbp
	jne	.L10
.L9:
	pop	rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	mov	eax, 1
	pop	rbp
	.cfi_def_cfa_offset 16
	pop	r12
	.cfi_def_cfa_offset 8
	ret
.L14:
	.cfi_restore_state
	lea	rcx, .LC3[rip]
	mov	edx, 18
	lea	rsi, .LC1[rip]
	lea	rdi, .LC4[rip]
	call	__assert_fail@PLT
.L7:
	lea	rcx, .LC3[rip]
	mov	edx, 25
	lea	rsi, .LC1[rip]
	lea	rdi, .LC6[rip]
	call	__assert_fail@PLT
.L15:
	lea	rcx, .LC3[rip]
	mov	edx, 19
	lea	rsi, .LC1[rip]
	lea	rdi, .LC5[rip]
	call	__assert_fail@PLT
	.cfi_endproc
.LFE5556:
	.size	_Z13HashTableCtorP9HashTablemPFiPKcE, .-_Z13HashTableCtorP9HashTablemPFiPKcE
	.p2align 4
	.globl	_Z13HashTableDtorP9HashTable
	.type	_Z13HashTableDtorP9HashTable, @function
_Z13HashTableDtorP9HashTable:
.LFB5557:
	.cfi_startproc
	endbr64
	push	r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	test	rdi, rdi
	je	.L23
	cmp	QWORD PTR 24[rdi], 0
	mov	r12, rdi
	je	.L24
	cmp	QWORD PTR 8[r12], 0
	mov	rdi, QWORD PTR 16[rdi]
	je	.L19
	mov	rbx, rdi
	xor	ebp, ebp
	.p2align 4,,10
	.p2align 3
.L20:
	mov	rdi, rbx
	add	rbp, 1
	add	rbx, 56
	call	_Z8ListDtorP4List@PLT
	cmp	QWORD PTR 8[r12], rbp
	ja	.L20
	mov	rdi, QWORD PTR 16[r12]
.L19:
	call	free@PLT
	pxor	xmm0, xmm0
	mov	eax, 1
	mov	QWORD PTR 16[r12], 0
	mov	QWORD PTR 24[r12], 0
	movups	XMMWORD PTR [r12], xmm0
	pop	rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbp
	.cfi_def_cfa_offset 16
	pop	r12
	.cfi_def_cfa_offset 8
	ret
.L23:
	.cfi_restore_state
	lea	rcx, .LC0[rip]
	mov	edx, 12
	lea	rsi, .LC1[rip]
	lea	rdi, .LC4[rip]
	call	__assert_fail@PLT
.L24:
	call	_ZL15HashTableVerifyPK9HashTable.part.0
	.cfi_endproc
.LFE5557:
	.size	_Z13HashTableDtorP9HashTable, .-_Z13HashTableDtorP9HashTable
	.section	.rodata.str1.1
.LC7:
	.string	"HashTableDump:\n{"
.LC8:
	.string	"}\n"
.LC9:
	.string	"    [%2ld]: "
	.text
	.p2align 4
	.globl	_Z13HashTableDump9HashTable
	.type	_Z13HashTableDump9HashTable, @function
_Z13HashTableDump9HashTable:
.LFB5558:
	.cfi_startproc
	endbr64
	push	r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	push	r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	push	rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	push	rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	sub	rsp, 8
	.cfi_def_cfa_offset 48
	cmp	QWORD PTR 72[rsp], 0
	mov	r12, QWORD PTR 56[rsp]
	je	.L33
	lea	rdi, .LC7[rip]
	call	puts@PLT
	test	r12, r12
	je	.L29
	mov	rbp, QWORD PTR 64[rsp]
	xor	ebx, ebx
	lea	r13, .LC9[rip]
	.p2align 4,,10
	.p2align 3
.L28:
	mov	rdx, rbx
	mov	rsi, r13
	mov	edi, 1
	xor	eax, eax
	call	__printf_chk@PLT
	add	rbx, 1
	mov	rdi, rbp
	add	rbp, 56
	call	_Z9ListPrintP4List@PLT
	cmp	r12, rbx
	jne	.L28
.L29:
	lea	rdi, .LC8[rip]
	call	puts@PLT
	add	rsp, 8
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	mov	eax, 1
	pop	rbx
	.cfi_def_cfa_offset 32
	pop	rbp
	.cfi_def_cfa_offset 24
	pop	r12
	.cfi_def_cfa_offset 16
	pop	r13
	.cfi_def_cfa_offset 8
	ret
.L33:
	.cfi_restore_state
	call	_ZL15HashTableVerifyPK9HashTable.part.0
	.cfi_endproc
.LFE5558:
	.size	_Z13HashTableDump9HashTable, .-_Z13HashTableDump9HashTable
	.section	.rodata.str1.8
	.align 8
.LC10:
	.string	"int FillHashTable(HashTable*, FILE*, int)"
	.section	.rodata.str1.1
.LC11:
	.string	"source"
.LC12:
	.string	"str"
.LC13:
	.string	"%s"
	.text
	.p2align 4
	.globl	_Z13FillHashTableP9HashTableP8_IO_FILEi
	.type	_Z13FillHashTableP9HashTableP8_IO_FILEi, @function
_Z13FillHashTableP9HashTableP8_IO_FILEi:
.LFB5559:
	.cfi_startproc
	endbr64
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 24
	.cfi_def_cfa_offset 80
	test	rdi, rdi
	je	.L47
	cmp	QWORD PTR 24[rdi], 0
	mov	rbx, rdi
	je	.L48
	mov	r13, rsi
	test	rsi, rsi
	je	.L37
	mov	r14d, edx
	xor	r12d, r12d
	lea	r15, .LC13[rip]
	test	edx, edx
	jg	.L38
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L41:
	mov	rdi, rbp
	add	r12d, 1
	call	[QWORD PTR 24[rbx]]
	xor	edx, edx
	mov	rsi, rbp
	cdqe
	div	QWORD PTR 8[rbx]
	movsx	rdx, edx
	lea	rax, 0[0+rdx*8]
	sub	rax, rdx
	mov	rdx, QWORD PTR 16[rbx]
	lea	rdi, [rdx+rax*8]
	call	_Z12ListPushBackP4ListPKc@PLT
	cmp	r14d, r12d
	je	.L39
.L38:
	mov	esi, 1
	mov	edi, 20
	call	calloc@PLT
	mov	rbp, rax
	test	rax, rax
	je	.L49
	mov	rdx, rax
	mov	rsi, r15
	xor	eax, eax
	mov	rdi, r13
	call	__isoc99_fscanf@PLT
	test	eax, eax
	jne	.L41
	mov	rdi, rbp
	mov	DWORD PTR 12[rsp], eax
	call	free@PLT
	mov	eax, DWORD PTR 12[rsp]
	add	rsp, 24
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	rbp
	.cfi_def_cfa_offset 40
	pop	r12
	.cfi_def_cfa_offset 32
	pop	r13
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L39:
	.cfi_restore_state
	add	rsp, 24
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	mov	eax, 1
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	rbp
	.cfi_def_cfa_offset 40
	pop	r12
	.cfi_def_cfa_offset 32
	pop	r13
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	ret
.L49:
	.cfi_restore_state
	lea	rcx, .LC10[rip]
	mov	edx, 79
	lea	rsi, .LC1[rip]
	lea	rdi, .LC12[rip]
	call	__assert_fail@PLT
.L37:
	lea	rcx, .LC10[rip]
	mov	edx, 74
	lea	rsi, .LC1[rip]
	lea	rdi, .LC11[rip]
	call	__assert_fail@PLT
.L48:
	call	_ZL15HashTableVerifyPK9HashTable.part.0
.L47:
	lea	rcx, .LC0[rip]
	mov	edx, 12
	lea	rsi, .LC1[rip]
	lea	rdi, .LC4[rip]
	call	__assert_fail@PLT
	.cfi_endproc
.LFE5559:
	.size	_Z13FillHashTableP9HashTableP8_IO_FILEi, .-_Z13FillHashTableP9HashTableP8_IO_FILEi
	.section	.rodata.str1.8
	.align 8
.LC14:
	.string	"int FillHashTable_alligned(HashTable*, __m256i*, int)"
	.section	.rodata.str1.1
.LC15:
	.string	"buf"
	.text
	.p2align 4
	.globl	_Z22FillHashTable_allignedP9HashTablePDv4_xi
	.type	_Z22FillHashTable_allignedP9HashTablePDv4_xi, @function
_Z22FillHashTable_allignedP9HashTablePDv4_xi:
.LFB5560:
	.cfi_startproc
	endbr64
	push	r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	push	r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	push	rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	push	rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	sub	rsp, 8
	.cfi_def_cfa_offset 48
	test	rdi, rdi
	je	.L60
	cmp	QWORD PTR 24[rdi], 0
	mov	rbx, rdi
	je	.L61
	mov	r13, rsi
	test	rsi, rsi
	je	.L53
	test	edx, edx
	jle	.L55
	lea	eax, -1[rdx]
	sal	rax, 5
	lea	r12, 32[rsi+rax]
	.p2align 4,,10
	.p2align 3
.L57:
	mov	edi, 32
	call	malloc@PLT
	mov	rbp, rax
	test	rax, rax
	je	.L62
	movdqu	xmm0, XMMWORD PTR 0[r13]
	movdqu	xmm1, XMMWORD PTR 16[r13]
	mov	rdi, rax
	add	r13, 32
	movups	XMMWORD PTR [rax], xmm0
	movups	XMMWORD PTR 16[rax], xmm1
	call	[QWORD PTR 24[rbx]]
	xor	edx, edx
	mov	rsi, rbp
	cdqe
	div	QWORD PTR 8[rbx]
	movsx	rdx, edx
	lea	rax, 0[0+rdx*8]
	sub	rax, rdx
	mov	rdx, QWORD PTR 16[rbx]
	lea	rdi, [rdx+rax*8]
	call	_Z12ListPushBackP4ListPKc@PLT
	cmp	r13, r12
	jne	.L57
.L55:
	add	rsp, 8
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	mov	eax, 1
	pop	rbx
	.cfi_def_cfa_offset 32
	pop	rbp
	.cfi_def_cfa_offset 24
	pop	r12
	.cfi_def_cfa_offset 16
	pop	r13
	.cfi_def_cfa_offset 8
	ret
.L62:
	.cfi_restore_state
	lea	rcx, .LC14[rip]
	mov	edx, 103
	lea	rsi, .LC1[rip]
	lea	rdi, .LC12[rip]
	call	__assert_fail@PLT
.L53:
	lea	rcx, .LC14[rip]
	mov	edx, 97
	lea	rsi, .LC1[rip]
	lea	rdi, .LC15[rip]
	call	__assert_fail@PLT
.L61:
	call	_ZL15HashTableVerifyPK9HashTable.part.0
.L60:
	lea	rcx, .LC0[rip]
	mov	edx, 12
	lea	rsi, .LC1[rip]
	lea	rdi, .LC4[rip]
	call	__assert_fail@PLT
	.cfi_endproc
.LFE5560:
	.size	_Z22FillHashTable_allignedP9HashTablePDv4_xi, .-_Z22FillHashTable_allignedP9HashTablePDv4_xi
	.p2align 4
	.globl	_Z15FindInHashTablePKc9HashTable
	.type	_Z15FindInHashTablePKc9HashTable, @function
_Z15FindInHashTablePKc9HashTable:
.LFB5561:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi
	call	[QWORD PTR 40[rsp]]
	xor	edx, edx
	mov	rsi, rbp
	cdqe
	div	QWORD PTR 24[rsp]
	movsx	rdx, edx
	lea	rax, 0[0+rdx*8]
	sub	rax, rdx
	mov	rdx, QWORD PTR 32[rsp]
	pop	rbp
	.cfi_def_cfa_offset 8
	lea	rdi, [rdx+rax*8]
	jmp	_Z10FindInListPK4ListPKc@PLT
	.cfi_endproc
.LFE5561:
	.size	_Z15FindInHashTablePKc9HashTable, .-_Z15FindInHashTablePKc9HashTable
	.p2align 4
	.globl	_Z20FindInHashTable_avx2Dv4_x9HashTable
	.type	_Z20FindInHashTable_avx2Dv4_x9HashTable, @function
_Z20FindInHashTable_avx2Dv4_x9HashTable:
.LFB5562:
	.cfi_startproc
	endbr64
	sub	rsp, 56
	.cfi_def_cfa_offset 64
	lea	rdi, 64[rsp]
	call	Crc32Hash_asm@PLT
	xor	edx, edx
	cdqe
	div	QWORD PTR 104[rsp]
	movsx	rdx, edx
	lea	rax, 0[0+rdx*8]
	sub	rax, rdx
	mov	rdx, QWORD PTR 112[rsp]
	push	QWORD PTR 88[rsp]
	.cfi_def_cfa_offset 72
	push	QWORD PTR 88[rsp]
	.cfi_def_cfa_offset 80
	push	QWORD PTR 88[rsp]
	.cfi_def_cfa_offset 88
	lea	rdi, [rdx+rax*8]
	push	QWORD PTR 88[rsp]
	.cfi_def_cfa_offset 96
	call	_Z15FindInList_avx2PK4ListDv4_x@PLT
	add	rsp, 88
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE5562:
	.size	_Z20FindInHashTable_avx2Dv4_x9HashTable, .-_Z20FindInHashTable_avx2Dv4_x9HashTable
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
