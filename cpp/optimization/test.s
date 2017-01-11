	.file	"cs_5.12.2.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN15RunTimeCaculateC2EPKc,"axG",@progbits,_ZN15RunTimeCaculateC5EPKc,comdat
	.align 2
	.weak	_ZN15RunTimeCaculateC2EPKc
	.type	_ZN15RunTimeCaculateC2EPKc, @function
_ZN15RunTimeCaculateC2EPKc:
.LFB972:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	clock_gettime
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE972:
	.size	_ZN15RunTimeCaculateC2EPKc, .-_ZN15RunTimeCaculateC2EPKc
	.weak	_ZN15RunTimeCaculateC1EPKc
	.set	_ZN15RunTimeCaculateC1EPKc,_ZN15RunTimeCaculateC2EPKc
	.section	.rodata
.LC0:
	.string	" timespan is:"
.LC1:
	.string	"s and "
.LC2:
	.string	"nsec."
	.section	.text._ZN15RunTimeCaculateD2Ev,"axG",@progbits,_ZN15RunTimeCaculateD5Ev,comdat
	.align 2
	.weak	_ZN15RunTimeCaculateD2Ev
	.type	_ZN15RunTimeCaculateD2Ev, @function
_ZN15RunTimeCaculateD2Ev:
.LFB975:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -56(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	clock_gettime
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	testq	%rax, %rax
	jns	.L3
	movq	-48(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	subq	$1, %rax
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	addq	$1000000000, %rax
	movq	%rax, -24(%rbp)
	jmp	.L4
.L3:
	movq	-48(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -24(%rbp)
.L4:
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %r12
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%r12, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEl
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEl
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE975:
	.size	_ZN15RunTimeCaculateD2Ev, .-_ZN15RunTimeCaculateD2Ev
	.weak	_ZN15RunTimeCaculateD1Ev
	.set	_ZN15RunTimeCaculateD1Ev,_ZN15RunTimeCaculateD2Ev
	.section	.rodata
.LC3:
	.string	"clear_array"
.LC4:
	.string	"clear_array:i"
	.text
	.globl	_Z11clear_arrayPii
	.type	_Z11clear_arrayPii, @function
_Z11clear_arrayPii:
.LFB977:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA977
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	leaq	-48(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	_ZN15RunTimeCaculateC1EPKc
	movl	$0, -52(%rbp)
	jmp	.L7
.L8:
	movl	-52(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	addl	$1, -52(%rbp)
.L7:
	movl	-52(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L8
	movl	$.LC4, %esi
	movl	$_ZSt4cout, %edi
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-52(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE0:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZN15RunTimeCaculateD1Ev
.LEHE1:
	jmp	.L11
.L10:
	movq	%rax, %rbx
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN15RunTimeCaculateD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L11:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE977:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA977:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE977-.LLSDACSB977
.LLSDACSB977:
	.uleb128 .LEHB0-.LFB977
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L10-.LFB977
	.uleb128 0
	.uleb128 .LEHB1-.LFB977
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB2-.LFB977
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE977:
	.text
	.size	_Z11clear_arrayPii, .-_Z11clear_arrayPii
	.section	.rodata
.LC5:
	.string	"clear_array_4"
.LC6:
	.string	"clear_array_4:i"
	.text
	.globl	_Z13clear_array_4Pii
	.type	_Z13clear_array_4Pii, @function
_Z13clear_array_4Pii:
.LFB978:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA978
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	leaq	-48(%rbp), %rax
	movl	$.LC5, %esi
	movq	%rax, %rdi
	call	_ZN15RunTimeCaculateC1EPKc
	movl	-76(%rbp), %eax
	subl	$3, %eax
	movl	%eax, -52(%rbp)
	movl	$0, -56(%rbp)
	jmp	.L13
.L14:
	movl	-56(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	movl	-56(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	movl	-56(%rbp), %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	movl	-56(%rbp), %eax
	cltq
	addq	$3, %rax
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	addl	$4, -56(%rbp)
.L13:
	movl	-56(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L14
	subl	$4, -56(%rbp)
	jmp	.L15
.L16:
	movl	-56(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	addl	$1, -56(%rbp)
.L15:
	movl	-56(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L16
	movl	$.LC6, %esi
	movl	$_ZSt4cout, %edi
.LEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-56(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE3:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
.LEHB4:
	call	_ZN15RunTimeCaculateD1Ev
.LEHE4:
	jmp	.L19
.L18:
	movq	%rax, %rbx
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN15RunTimeCaculateD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume
.LEHE5:
.L19:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE978:
	.section	.gcc_except_table
.LLSDA978:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE978-.LLSDACSB978
.LLSDACSB978:
	.uleb128 .LEHB3-.LFB978
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L18-.LFB978
	.uleb128 0
	.uleb128 .LEHB4-.LFB978
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB978
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE978:
	.text
	.size	_Z13clear_array_4Pii, .-_Z13clear_array_4Pii
	.globl	_Z10write_readPiS_iPKc
	.type	_Z10write_readPiS_iPKc, @function
_Z10write_readPiS_iPKc:
.LFB979:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movl	%edx, -68(%rbp)
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN15RunTimeCaculateC1EPKc
	movl	-68(%rbp), %eax
	movl	%eax, -40(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L21
.L22:
	movq	-64(%rbp), %rax
	movl	-36(%rbp), %edx
	movl	%edx, (%rax)
	movq	-56(%rbp), %rax
	movl	(%rax), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
.L21:
	movl	-40(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -40(%rbp)
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	jne	.L22
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN15RunTimeCaculateD1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE979:
	.size	_Z10write_readPiS_iPKc, .-_Z10write_readPiS_iPKc
	.section	.rodata
.LC7:
	.string	"src diff with dest"
.LC8:
	.string	"src same as dest"
	.text
	.globl	main
	.type	main, @function
main:
.LFB980:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4000, %rsp
	leaq	-4000(%rbp), %rax
	movl	$1000, %esi
	movq	%rax, %rdi
	call	_Z11clear_arrayPii
	leaq	-4000(%rbp), %rax
	movl	$1000, %esi
	movq	%rax, %rdi
	call	_Z13clear_array_4Pii
	leaq	-4000(%rbp), %rax
	leaq	4(%rax), %rsi
	leaq	-4000(%rbp), %rax
	movl	$.LC7, %ecx
	movl	$10000, %edx
	movq	%rax, %rdi
	call	_Z10write_readPiS_iPKc
	leaq	-4000(%rbp), %rsi
	leaq	-4000(%rbp), %rax
	movl	$.LC8, %ecx
	movl	$10000, %edx
	movq	%rax, %rdi
	call	_Z10write_readPiS_iPKc
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE980:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB990:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L25
	cmpl	$65535, -8(%rbp)
	jne	.L25
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE990:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z11clear_arrayPii, @function
_GLOBAL__sub_I__Z11clear_arrayPii:
.LFB991:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE991:
	.size	_GLOBAL__sub_I__Z11clear_arrayPii, .-_GLOBAL__sub_I__Z11clear_arrayPii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z11clear_arrayPii
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
