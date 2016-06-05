;Laborator 4 - probleme propuse

;Scrieti 2 programe in limbaj de asamblare care sa rezolve una dintre urmatoarele expresii ;aritmetice in interpretarea cu semn si respectiv in interpretarea fara semn, tipul ;variabilelor fiind specificat.

;11. (a+b)/(2-b*b+b/c)
;a-doubleword; b,c-byte


;interpretarea fara semn

assume cs:code, ds:data
data segment
	a dd 125
	b db 1
	c db 1
data ends

code segment
start:
	mov ax, data
	mov ds, ax

	mov al,b
	mul b	; ax=b*b
	mov cx,ax ; cx=b*b

	mov al,b
	mov ah,0 ; ax = b
	;cbw
	div c ; al = b/c

	sub ax, cx  ;ax = b/c - b*b
	mov cx,ax
	
	mov al, 2
	mov ah, 0
	;cbw
	add cx, ax ; cx = 2 - b*b + b/c

	mov al,b
	mov ah,0
	mov dx,0  ;dx:ax = b
	
	add ax,word ptr a
	adc dx,word ptr a+2
	
	div cx

mov ax, 4C00h
int 21h
code ends
end start