section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax
	xor rcx, rcx
	not rcx
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	ret