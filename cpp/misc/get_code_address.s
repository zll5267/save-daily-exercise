	.file	"get_code_address.cpp"
	.section	.rodata
.LC0:
	.string	"a address is:%p\n"
.LC1:
	.string	"b address is:%p\n"
.LC2:
	.string	"main address is:%p\n"
.LC3:
	.string	"b-a:%d\n"
.LC4:
	.string	"local at %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	%gs:20, %eax
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
.L2:
	movl	$.L2, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
.L3:
	movl	$.L3, 32(%esp)
	movl	32(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$main, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	32(%esp), %edx
	movl	28(%esp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$0, %eax
	movl	44(%esp), %ecx
	xorl	%gs:20, %ecx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
