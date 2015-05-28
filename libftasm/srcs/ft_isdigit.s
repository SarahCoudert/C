section .text
	global _ft_isdigit

_ft_isdigit:
	push rdi
	mov rax, 1
	cmp rdi, 48
	jl end
	cmp rdi, 57
	jg end
	pop rdi
	ret

end:
	pop rdi
	xor rax, rax
	ret