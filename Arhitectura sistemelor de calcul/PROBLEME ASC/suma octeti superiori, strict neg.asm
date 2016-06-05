; Se da un sir de cuvinte. Sa se calculeze suma octetilor superiori strict negativi a cuvintelor din sir.

assume cs:code,ds:data
data segment
	s 	dw	1025,32,57,-9
	l	equ	($-s)/2
	suma	dw	0
data ends
code segment
	mov ax,data
	mov ds,ax
	
	mov si,offset si+1
	mov cx,l
	cld
	jcxz final
	repeta:
		lodsb ;ds:si ->al, inc si
		inc si
		cmp al,0
		jge next
		cbw
		add suma,ax
	next:
		loop repeta
	final:
		mov ax,4c00h
		int 21h
code ends
end start