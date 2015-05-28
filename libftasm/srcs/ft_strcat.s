section .text
	global _ft_strcat

_ft_strcat:
	push rsi
	mov rax, rdi
	jmp while1

while1:
	cmp byte[rdi], 0
	je while2
	inc rdi
	jne while1

while2:
	cmp byte[rsi], 0
	je  end
	mov bl, byte[rsi]
	mov byte[rdi], bl
	inc rsi
	inc rdi
	jmp while2

end:
	mov byte[rdi], 0
	pop rsi
	ret