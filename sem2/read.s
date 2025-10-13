	.file	"read.cpp"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"large_file.txt"
.LC1:
	.string	"open failed"
.LC2:
	.string	"read failed"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 4096
	or	QWORD PTR [rsp], 0
	sub	rsp, 32
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	esi, 0
	lea	rax, .LC0[rip]
	mov	rdi, rax
	mov	eax, 0
	call	open@PLT
	mov	DWORD PTR -4124[rbp], eax
	cmp	DWORD PTR -4124[rbp], -1
	jne	.L4
	lea	rax, .LC1[rip]
	mov	rdi, rax
	call	perror@PLT
	mov	eax, 1
	jmp	.L7
.L5:
	mov	rdx, QWORD PTR -4120[rbp]
	lea	rax, -4112[rbp]
	mov	rsi, rax
	mov	edi, 1
	call	write@PLT
.L4:
	lea	rcx, -4112[rbp]
	mov	eax, DWORD PTR -4124[rbp]
	mov	edx, 4096
	mov	rsi, rcx
	mov	edi, eax
	call	read@PLT
	mov	QWORD PTR -4120[rbp], rax
	cmp	QWORD PTR -4120[rbp], 0
	setg	al
	test	al, al
	jne	.L5
	cmp	QWORD PTR -4120[rbp], -1
	jne	.L6
	lea	rax, .LC2[rip]
	mov	rdi, rax
	call	perror@PLT
	mov	eax, DWORD PTR -4124[rbp]
	mov	edi, eax
	call	close@PLT
	mov	eax, 1
	jmp	.L7
.L6:
	mov	eax, DWORD PTR -4124[rbp]
	mov	edi, eax
	call	close@PLT
	mov	eax, 0
.L7:
	mov	rdx, QWORD PTR -8[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
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
