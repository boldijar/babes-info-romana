; II 214

assume cs:code, ds:data
data segment
	sir dw 1212h,1114h,2346h,5501h,0599h
	lsir equ ($-sir)/2;lungimea sirului
	tabela db '0123456789ABCDEF';tabela pentru xlat
	saispe db 16
	q db ' catul= $'
	r db ' restul= $'
	a db ?
	b db ?
data ends
code segment
	start:
mov ax,data
mov ds,ax
lea si,sir;punem in si offsetul sirului
mov ax,0;initializam ax cu 0
mov al,[si];punem in al byteul inferior al primului word
mov cx,lsir;in cx lungimea sirului
repeta:
mov ah,[si];punem in ah byteul inferior corespunzator wordului spre care pointeaza bp
cmp al,ah;comparam al cu ah
ja jos;daca ah>al
mov al,ah;al:=ah
jos:;altfel trece mai departe
add si,2;bp pointeaza spre urmatorul word
loop repeta
mov a,al;maximul se pune in a
	
mov si, offset sir;bp pointeaza din nou la inceputul sirului
inc si;si:=si+1 pentru a pointa spre byteul superior
mov ax,0;initializam ax
mov al,[si];punem in al bytetul superior al primului word
mov cx,lsir;punem in cx lungimea sirului
repeta2:
mov ah,[si];punem in ah byteul superior corespunzator wordului spre care pointeaza bp
cmp al,ah;cumparam al cu ah
jb jos2;daca al<ah
mov al,ah;al:=ah
jos2:;altfel trece mai departe
add si,2;bp pointeaza spre urmatorul word
loop repeta2
mov b,al;minimul se pune in b
	
mov ax,0;initializam ax
mov al,a;punem maximul in al
div b;il impartim la b
push ax;punem ax pe stiva
mov bl,al;ramane doar catul impartirii
mov cx,8;initializam cx
mov dx,offset q
mov ah,09h
int 21h
repeta3:
shl bl,1
jc unu
mov ah,02h
mov dl,'0'
int 21h;impartim catul la 16
loop repeta3
mov ah,02h
mov dl,'b'
int 21h
jmp msg
unu:
	mov ah,02h
	mov dl,'1'
	int 21h
loop repeta3
mov ah,02h
mov dl,'b'
int 21h
msg:
	mov dx,offset r
	mov ah,09h
	int 21h
rest:

	pop ax
	mov bl,ah
	mov cx,8
	repeta4:
		shl bl,1
		jc unu1
		mov ah,02h
		mov dl,'0'
		int 21h
	loop repeta4
	mov ah,02h
	mov dl,'b'
	int 21h
	jmp final
	unu1:
		mov ah,02h
		mov dl,'1'
		int 21h
	loop repeta4
	mov ah,02h
mov dl,'b'
int 21h
	final:
	
	mov ax,4c00h
	int 21h
code ends
end start
