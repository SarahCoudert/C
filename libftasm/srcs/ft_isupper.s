section .text
	global _ft_isupper

_ft_isupper:
	xor rax, rax
	cmp rdi, 65
	jl end
	cmp rdi, 90
	jg end
	mov rax, 1

end:
	ret