assume cs:code, ds:data
data segment
	sir dw 1212h,1114h,2346h,5501h,0599h
	lsir equ ($-sir)/2;lungimea sirului
	q db ' catul= $'
	r db ' restul= $'
	a db ?
	b db ?
	zece db 10
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
push ax
mov dx,offset q;afisam stringul q
mov ah,09h
int 21h
mov cx,0
mov ah,0
	repeta3:
		div zece
		push ax
		inc cx
		cmp al,0
	jne repeta3
	afiscat:
		pop ax
		mov dl,ah
		add dl,'0'
		mov ah,02h
		int 21h
	loop afiscat
		
mov dx,offset r
mov ah,09h
int 21h
pop ax
xchg al,ah
mov ah,0
mov cx,0
	repeta4:
		div zece
		push ax
		inc cx
		cmp al,0
	jne repeta4
	afisrest:
		pop ax
		mov dl,ah
		add dl,'0'
		mov ah,02h
		int 21h
	loop afisrest

mov ax,4c00h
int 21h
code ends
end start
