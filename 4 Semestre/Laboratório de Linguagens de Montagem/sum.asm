section .data
	x db '5' ; declarado como caractere
	y db '3' ; declarado como caractere
	msg db "A soma de x e y é: ", 0
	len equ $ - msg

segment .bss
	sum resb 1

section .text
global _start

_start:
	mov eax, [x] ; atribui x ao registrador
	sub eax, '0' ; boas práticas no NASM (convertemos o caractere em número)

	mov ebx, [y] ; atribui y ao registrador
	sub ebx, '0' ; boas práticas no NASM (convertemos o caractere em número)
	
	add eax, ebx ; soma dos valores, registrada em eax
	add eax, '0' ; boas práticas no NASM (convertemos o número em caractere)

	mov [sum], eax ; armazena a soma de EAX na variável sum

	; imprime msg
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 0x80

	; imprime o resultado
	mov eax, 4
	mov ebx, 1
	mov ecx, sum ; guarda sum em ecx
	mov edx, 1
	int 0x80

	mov eax, 1
	int 0x80