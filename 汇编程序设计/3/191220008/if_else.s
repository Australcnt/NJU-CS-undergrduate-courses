	.file	"if_else.c"
	.text
	.globl	if_else
	.type	if_else, @function
if_else:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	cmpl	$0, 8(%ebp)
	jle	.L2
	cmpl	$29, 12(%ebp)
	jg	.L2
	movl	$0, -4(%ebp)
	jmp	.L3
.L2:
	cmpl	$0, 8(%ebp)
	jle	.L4
	cmpl	$30, 12(%ebp)
	jle	.L4
	movl	$1, -4(%ebp)
	jmp	.L3
.L4:
	movl	$2, -4(%ebp)
.L3:
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	if_else, .-if_else
	.section	.rodata
.LC0:
	.string	"%d %d"
.LC1:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	subl	$4, %esp
	leal	-16(%ebp), %eax
	pushl	%eax
	leal	-20(%ebp), %eax
	pushl	%eax
	pushl	$.LC0
	call	scanf
	addl	$16, %esp
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	subl	$8, %esp
	pushl	%edx
	pushl	%eax
	call	if_else
	addl	$16, %esp
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-12(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L8
	call	__stack_chk_fail
.L8:
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
