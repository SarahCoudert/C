section .text
	global _ft_memalloc
	extern _malloc

_ft_memalloc:
	xor rax, rax
	cmp rdi, 0
	je end
	call _malloc

end:
	ret