 ;(a*a-b+7)/(2+a) fara semn

assume cs:code, ds:data

data segment
	a db 2
        b dd 4
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	mov al, a
        mul a
       	add ax, 7
	mov dx, 0 ; conversie din word in doubleword
  	mov bx, word ptr b+2
	mov cx, word ptr b
	sub ax, cx
	sbb dx, bx ; dx:ax=(a*a-b+7)
 	mov bl, a 
	add bl, 2
	mov bh, 0 ; conversie din byte in word
	div bx
	
	mov dx,4c00h
	int 21h
code ends
end start