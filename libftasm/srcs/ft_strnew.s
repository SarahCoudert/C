section .text
	global	_ft_strnew
	extern _malloc
	extern _ft_bzero

_ft_strnew:
	push rdi
	call _malloc
	pop rdi
	push rax
	push rdi
	pop rsi
	pop rdi
	call _ft_bzero

end:
	ret