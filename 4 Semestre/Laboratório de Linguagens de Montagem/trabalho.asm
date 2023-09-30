section .data
	prompt db "Digite um número: ", 0
	lenprompt equ $ - prompt
	num db '5'
	mensagem1 db "O menor número é ", 0
	len1 equ $ - mensagem1
	mensagem2 db "Os dois números são iguais!", 0
	len2 equ $ - mensagem2

section .bss
	menor_numero resb 1
	entrada resb 1

section .text
global _start

_start:
	; escreve a mensagem no prompt
	mov eax, 4
	mov ebx, 1
	mov ecx, prompt
	mov edx, lenprompt
	int 0x80

	; lê a entrada do teclado e gravar no buffer
	mov eax, 3
	mov abx, 0
	mov ecx, entrada
	mov edx, 1
	int 0x80

	mov eax, [num]
	mov ebx, [entrada]
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
	mov [menor_numero], ebx
	jmp print

numero2_e_maior: ; caso 3
	mov [menor_numero], eax
	jmp print


print:
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagem1
	mov edx, len1
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, menor_numero
	mov edx, 1
	int 0x80
	jmp end

end:
	mov eax, 1
	xor ebx, ebx ; zera o conteúdo dos registradores
	int 0x80


	