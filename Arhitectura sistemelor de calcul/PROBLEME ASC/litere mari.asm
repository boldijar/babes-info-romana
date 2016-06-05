; Se da un sir de caractere litere mici. Sa se obtina literele mari.

assume cs:code, ds:data
data segment
	s	db	'a','b','c'
	l equ $-s
	d	db	l dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	mov si,offset s
	mov di,offset d
	cld
	mov cx,l
	jcxz final
	repeta:
		lodsb
		sub al,32
		stosb
	loop repeta
	final:
		mov ax,4c00h
		int 21h
code ends
end start

	