 ;(a+b)/(2-b*b+b/c) a-doubleword; b,c-byte fara semn

assume cs:code, ds:data

data segment
	a dd 2
        b db 4
	c db 5
	
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	mov bx, word ptr a+2
	mov cx, word ptr a
	mov al, b
	mov ah, 0
	mov dx, 0
	add cx, ax
	adc bx, dx
	mov al, b
	mov ah, 0
	mov dl, c
	div dl
	add al, 2
	mov dl, al
	mov dh, 0
	mov al, b
	mul b
	sub dx, ax
	mov ax, cx
	mov cx, dx
	mov dx, bx
	div cx

	mov dx,4c00h
	int 21h

code ends
end start