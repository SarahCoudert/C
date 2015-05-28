;SYS		RDI				RSI					RDX					RAX
;4 -> write(int fildes,		const void *buf,	size_t nbyte);	-> code erreur
;3 -> read (int fd,			char *buff,			int size);		-> byte lues

section .text
	global _ft_cat
	extern _malloc

;section .data
;	buff db 1024

_ft_cat:
	mov rdi, r8			;on met le file descriptor dans r8 pour l'avoir plus tard
	mov rdi, 1024		;met la taille dans rdi pour le malloc
	call _malloc		;on malloc avec la taille mise dans rdi
	jc end				;si malloc foire on se casse
	push rax			;on met le pointeur sur la stack -----------------> push

read:
	mov rdi, r8				; on recupere la chaine dans rsi ------------------> pop
	pop rdi				;on met le contenu de r8 (le fd) dans rdi pou read
	push rdi
	mov rax, 0x2000003	;on met l appel system read dans rax
	mov rdx, 1024		;on met dans rdx la longueur qu'on veut lire
	syscall				;on appelle read
	jc end_fail			; si ca foire on quitte

write:
	cmp rax, 0 			;on regarde si read a renvoye 0
	je  end 			;si oui on se barre
	mov rdx, rax		;on met le nombre de char lu dans dans rdx pour les lire
	mov rax, 0x2000004	;on met write dans rax
	mov rdi, 1			;on met l output dans rdi
	syscall 			;on appelle write
	jmp read 			;on recommence

end_fail:
	pop rsi
	xor rax, rax
	ret

end :
	pop rdi
	ret