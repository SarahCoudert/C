section .text
	global _ft_memcpy


_ft_memcpy:
	push rdi
	mov rax, rsi
	mov rcx, rdx
	cld
	repne movsb
	pop rax
	ret