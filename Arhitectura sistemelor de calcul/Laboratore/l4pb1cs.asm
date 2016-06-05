 ;(a*a-b+7)/(2+a) cu semn

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
        imul a
       	add ax, 7
	cwd ; conversie din word in doubleword
  	mov bx, word ptr b+2
	mov cx, word ptr b
	sub ax, cx
	sbb dx, bx ; dx:ax=(a*a-b+7)
	mov bx, ax
 	mov al, a 
	add al, 2
	cbw
	mov cx, ax ; cx=2+a
	mov ax,bx
	idiv cx
	
	mov dx,4c00h
	int 21h
code ends
end start