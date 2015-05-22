section .text
	global _ft_tolower

_ft_tolower:
	mov rax, rdi
	cmp rdi, 65
	jl no
	cmp rdi, 90
	jg no
	add rax, 32
	ret

no:
	ret