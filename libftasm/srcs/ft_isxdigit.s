section .text
	global	_ft_isxdigit

_ft_isxdigit:
	cmp rdi, 48 ; '0'
	jl  no
	cmp rdi, 57; '9'
	jle yes
	cmp rdi, 65 ; 'A'
	jl  no
	cmp rdi, 70	; 'F'
	jle yes
	cmp rdi, 97 ; 'a'
	jl  no
	cmp rdi, 102 ;'f'
	jle yes

no:
	mov rax, 0
	jmp end

yes:
	mov rax, 1

end:
	ret