assume cs:code,ds:data
data segment
	a	db	-15,4,-128,2,199,-1
	b	dw	0FF52h
	c	dd	3
	;d	dw	a
	e	dd	b
	f	dw	c
	;g	dw	a+2
	
data ends

code segment
start:
mov ax,data
mov ds,ax
mov bx,1
lea ax,[bx]
mov si,ax
mov al,[si]
mov si,ax
lodsb
les bx,c
mov cx,[bx]
xor ch,ch

dinnou:
	dec cx
	
loop dinnou
mov ax,4c00h
int 21h
code ends
end start