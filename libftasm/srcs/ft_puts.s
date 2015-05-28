section .data
	msg db "(null)", 10

section .text
	global _ft_puts

_ft_puts:
	xor r9, r9
	cmp rdi, 0
	je  end_null

len:
	cmp	byte[rdi + r9], 0
	je	print
	inc r9
	jmp len

print:
	mov rax, 0x2000004
	mov rsi, rdi
	mov rdi, 1
	mov rdx, r9
	syscall

newline:
	mov rax, 0x2000004
	lea rsi, [rel msg + 6]
	mov rdi, 1
	mov rdx, 1
	syscall
	jmp end

end_null:
	mov rax, 0x2000004
	lea rsi, [rel msg]
	mov rdi, 1
	mov rdx, 7
	syscall

end:
	ret
