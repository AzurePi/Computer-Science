section .data
	hello db 'Hello World!', 0x0A	; string a ser apresentada
	hello_len equ $ - hello		; determina o comprimento da string

section .text
	global_start

_start
	mov eax, 4	; syscall para sys_write
	mov ebx, 1	; descrição da saída 1 (stdout)

	mov ecx, hello		; endereço da string (a variável definida em .data)
	mov edx, hello_len	; quantidade de bytes da string
	int 0x80;		; chamada da SysCall 4, responsável pela escrita

	mov eax, 1	; registrador EAX recebe o valor 1, responsável pelo encerramento do programa
	xor ebx, ebx	; exit status 0
	int 0x80	; chamada ds Syscall 1, presente no registrados EAX