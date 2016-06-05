	.file	"m1.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"zero"
	.text
	.p2align 4,,15
	.globl	zero
	.type	zero, @function
zero:
.LFB27:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	cine(%rip), %eax
	testl	%eax, %eax
	je	.L8
.L5:
	jmp	.L5
.L8:
	movl	$.LC0, %edi
	call	puts
	movl	$1, cine(%rip)
	jmp	.L5
	.cfi_endproc
.LFE27:
	.size	zero, .-zero
	.p2align 4,,15
	.globl	unu
	.type	unu, @function
unu:
.LFB28:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	cmpl	$1, cine(%rip)
	je	.L15
.L13:
	jmp	.L13
.L15:
	movl	$10, %edi
	call	putchar
	movl	$0, cine(%rip)
	jmp	.L13
	.cfi_endproc
.LFE28:
	.size	unu, .-unu
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB29:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	xorl	%ecx, %ecx
	movl	$zero, %edx
	movq	%rsp, %rdi
	xorl	%esi, %esi
	call	pthread_create
	leaq	8(%rsp), %rdi
	xorl	%ecx, %ecx
	movl	$unu, %edx
	xorl	%esi, %esi
	call	pthread_create
	movq	(%rsp), %rdi
	xorl	%esi, %esi
	call	pthread_join
	movq	8(%rsp), %rdi
	xorl	%esi, %esi
	call	pthread_join
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE29:
	.size	main, .-main
	.globl	cine
	.bss
	.align 16
	.type	cine, @object
	.size	cine, 4
cine:
	.zero	4
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
