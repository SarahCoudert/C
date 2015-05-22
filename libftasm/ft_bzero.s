section .text
	global _ft_bzero

_ft_bzero:
	mov rax, rdi
	cmp rdi, 0
	jne while
	ret

while:
	mov byte[rdi], 0
	dec rsi
	inc rdi
	cmp rsi, 0
	jg while
	ret