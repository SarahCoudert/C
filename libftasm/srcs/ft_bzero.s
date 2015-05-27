section .text
	global _ft_bzero

_ft_bzero:
	push rdi
	mov rax, 0
	mov rcx, rsi
	cld
	repne stosb
	pop rax
	ret