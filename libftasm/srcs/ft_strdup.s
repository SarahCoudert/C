section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

_ft_strdup:
	enter 0, 0
	push rdi			;met la chaine dans la stack
	call _ft_strlen		;met rax a la taille de rdi
	mov rcx, rax 		;met la taille dans rcx
	push rcx			;met la taille sur la stack
	mov rdi, rax		;met la taille dans rdi
	inc rdi				;augmente la taille de 1 (\0)
	call _malloc		;on malloc avec la taille mise sur la stack
	jc end				;si malloc foire on se casse
	pop rcx				;on recupere la chaine allouee dans rcx
	pop rsi				;recupere la chaine de depart
	mov rdi, rax		;on met rax dans rdi
	cld					;on clear le flag de deplacement
	repne movsb			;on copie la string

end:
	leave
	ret 				;on se casse