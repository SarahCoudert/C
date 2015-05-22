section .text
	global _ft_isalpha

_ft_isalpha:
	mov rax, 1
	cmp rdi, 65
	jl no
	cmp rdi, 122
	jg no
	cmp rdi, 90
	jle yes
	cmp rdi, 97
	jge yes

no:
	xor rax, rax
	ret

yes:
	mov rax, 1
	ret
 