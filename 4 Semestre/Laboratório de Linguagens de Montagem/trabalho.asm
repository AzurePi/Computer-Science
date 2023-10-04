section .data
	num dd '5'

	prompt db "Digite um número: ", 0
	lenprompt equ $ - prompt

	mensagem1 db "O menor número é ", 0
	len1 equ $ - mensagem1

	mensagem2 db "Os dois números são iguais!", 0
	len2 equ $ - mensagem2


section .bss
	entrada resb 1		; buffer para a entrada
	menor_numero resb 1	; variável auxiliar para impressão


section .text
global _start

_start:
	; escreve a mensagem no prompt
	mov eax, 4
	mov ebx, 1
	mov ecx, prompt
	mov edx, lenprompt
	int 0x80

	; lê a entrada do teclado e grava no buffer
	mov eax, 3
	mov ebx, 0
	mov ecx, entrada
	mov edx, 1
	int 0x80

	mov eax, [num]
	mov ebx, [entrada]
	cmp eax, ebx

	je numeros_iguais	; caso 1 (jump if equal)
	jg num_eh_maior		; caso 2 (jump if greater)
	jb entrada_eh_maior	; caso 3 (jump if less)


; caso 1
numeros_iguais:
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagem2
	mov edx, len2
	int 0x80
	jmp end

; caso 2
num_eh_maior:
	mov [menor_numero], ebx
	jmp print

; caso 3
entrada_eh_maior:
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
	int 0x80