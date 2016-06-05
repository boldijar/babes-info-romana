assume cs:code,ds:data
data segment
	s	db	123,34,59,112
	l	equ	$-s
data ends
code segment
start:
	push data
	pop ds
	
	lea si,s
	mov cx,l
	jcxz final
	repeta:
		mov bl,byte ptr ds:[si]
		inc si
		push cx
		mov cx,4
		mutare:
			shr bl,1
			rcr ax,1
		loop mutare
		pop cx
	loop repeta
	final:
		mov ax,4C00h
		int 21h
code ends
end start