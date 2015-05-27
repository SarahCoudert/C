section .text
	global _ft_isprint

_ft_isprint:
	push rdi
	mov rax, 1
	cmp rdi, 32
	jl end
	cmp rdi, 126
	jg end
	pop rdi
	ret

end:
	pop rdi
	xor rax, rax
	ret