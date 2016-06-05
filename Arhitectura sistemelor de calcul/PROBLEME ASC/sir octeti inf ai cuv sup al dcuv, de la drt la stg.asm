; Se da un sir de dublu cuvinte. Sa se construiasca sirul octetilor inferiori ai cuvintelor superioare ale dublucuvintelor din sir, de la dreapta spre stanga.

assume cs:code,ds:data
data segment
	s	dw	1025,159,9
	l	equ	($-s)/4
	d	db	l dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	mov si,offset s+l*4-2
	mov di,offset d
	mov cx,l
	jcxz final
	
	repeta
		std  ; DF=1
		lodsb	; ds:si ->al, dec si
		sub si,3
		cld
		stosb	; al -> es:di, inc di
	loop repeta
	
	final:
		mov ax,4c00h
		int 21h
code ends
end start