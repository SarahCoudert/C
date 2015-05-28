section .text
	global _ft_isascii

_ft_isascii:
	push rdi
	mov rax, 1
	cmp rdi, 0
	jl end
	cmp rdi, 127
	jg end
	pop rdi
	ret

end:
	pop rdi
	xor rax, rax
	ret