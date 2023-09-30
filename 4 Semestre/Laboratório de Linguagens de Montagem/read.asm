; variáveis definidas na memória
section .data
	mensagem1 db "Digite alguma coisa: ", 0
	len1 equ $ - mensagem1
	mensagem2 db "Você digitou: ", 0
	len2 equ $ - mensagem2

; variávies não definidas na meória
section .bss
	entrada resb 255 ; espaço (buffer) reservado na memória para armazenar uma entrada


section .text

global _start

_start:
	; escreve a mensagem no prompt
	mov EAX, 4
	mov EBX, 1
	mov ECX, mensagem1
	mov EDX, len1
	int 0x80	; syscall (analisa o estado do processador e executa algo de acordo com os valores dos registradores)

	; lê a entrada do teclado e gravar no buffer
	mov EAX, 3
	mov EBX, 0
	mov ECX, entrada
	mov EDX, 255
	int 0x80	; syscall (analisa o estado do processador e executa algo de acordo com os valores dos registradores)

	; escrever a mensagem de saída
	mov EAX, 4
	mov EBX, 1
	mov ECX, mensagem2
	mov EDX, len2
	int 0x80

	mov EAX, 4
	mov EBX, 1
	mov ECX, entrada
	mov EDX, 255
	int 0x80
	
	; encerra o programa
	mov EAX, 1
	int 0x80	; syscal para EXIT