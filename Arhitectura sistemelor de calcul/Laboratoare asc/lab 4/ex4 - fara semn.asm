;Scrieti 2 programe in limbaj de asamblare care sa rezolve una dintre urmatoarele expresii
; aritmetice in interpretarea cu semn si respectiv in interpretarea fara semn, tipul 
;variabilelor fiind specificat.

;4. (a*2+b/2+e)/(c-d)
;a-word; b,c,d-byte; e-doubleword

assume cs:code, ds:data

data segment
	a dw 300
	b db 20
	c db 3
	d db 1
	e dd 90
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	mov ax, a
	mov bx, 2
	mul bx;  dx:ax = a*2
	
	mov bx, ax
	mov cx, dx ; cx:bx = a*2
	
	mov al, b
	mov ah, 0
	mov dl, 2
	div dl ; al = b/2
	mov ah,0; ax = b/2
	mov dx,0 ;dx:ax = b/2
	
	add bx, ax
	adc cx, dx ;cx:bx = a*2 + b/2
	
	mov ax, word ptr e
	mov dx, word ptr e+2 ;dx:ax = e
	
	add ax, bx
	adc dx, cx  ; dx:ax = a*2+b/2+e
	
	mov bl, c
	mov bh, 0
	mov cl, d
	mov ch, 0
	sub bx,cx ; bx = c-d
	
	div bx ; ax = (a*2+b/2+e)/(c-d)
	
	mov ax, 4c00h
	int 21h

code ends
end start