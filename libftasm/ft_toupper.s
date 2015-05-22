section .text
	global _ft_toupper

_ft_toupper:
	mov rax, rdi
	cmp rdi, 97
	jl no
	cmp rdi, 122
	jg no
	sub rax, 32
	ret

no:
	ret