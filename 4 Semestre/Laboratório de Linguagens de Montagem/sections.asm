section .data
	numero1 dd '2'
	numero2 dd '3'
	mensagem1 db "O maior número é: ", 0
	len1 equ $ - mensagem1
	mensagem2 db "Os dois números são iguais!", 0
	len2 equ $ - mensagem2

section .bss
	maior_numero resb 1

section .text
global _start


_start:
	mov eax, [numero1]
	mov ebx, [numero2]
	cmp eax, ebx

	je numeros_iguais ; caso 1 (jump if equal)
	jg numero1_e_maior ; caso 2 (jump if greater)
	jb numero2_e_maior ; caso 3 (jump if less)


numeros_iguais: ; caso 1
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagem2
	mov edx, len2
	int 0x80
	jmp end;

numero1_e_maior: ; caso 2
	mov [maior_numero], eax
	jmp print

numero2_e_maior: ; caso 3
	mov [maior_numero], ebx
	jmp print


print:
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagem1
	mov edx, len1
	int 0x80
	jmp print2

print2:
	mov eax, 4
	mov ebx, 1
	mov ecx, maior_numero
	mov edx, 1
	int 0x80
	jmp end


end:
	mov eax, 1
	xor ebx, ebx ; zera o conteúdo dos registradores
	int 0x80