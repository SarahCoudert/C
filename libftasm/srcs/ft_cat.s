;SYS		RDI				RSI					RDX					RAX
;4 -> write(int fildes,		const void *buf,	size_t nbyte);	-> code erreur
;3 -> read (int fd,			char *buff,			int size);		-> byte lues

section .data
	buf:
		.string db 32
		.size equ $ - .string

section .text
	global _ft_cat

_ft_cat:
	push rdi												;-> push fd
	cmp rdi, 0
	jle end

read:
	pop rdi 												; <- pop fd
	push rdi 												; -> push fd
	lea rsi, [rel buf.string]
	mov rax, 0x2000003
	mov rdx, buf.size ;size
	syscall
	jc end

write:
	cmp rax, 0
	jle  end
	mov rdi, 1 ;sortie
	mov rdx, buf.size ;size
	mov rax, 0x2000004
	syscall
	jc end
	jmp read

end :
	pop rdi
	xor rax, rax
	ret