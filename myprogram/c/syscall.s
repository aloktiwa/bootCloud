	.file	"syscall.c"
	.comm	base,8,8
	.section	.rodata
.LC0:
	.string	"Hello workd\n"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$14, %ecx
	movl	$.LC0, %edx
	movl	$1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	syscall
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.6 20110731 (Red Hat 4.4.6-3)"
	.section	.note.GNU-stack,"",@progbits
