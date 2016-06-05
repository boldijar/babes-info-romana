; II 214

assume cs:code, ds:data
data segment
	sir dw 1212h,1114h,2346h,5501h,0599h
	lsir equ ($-sir)/2;lungimea sirului
	tabela db '0123456789ABCDEF';tabela pentru xlat
	saispe db 16
	q db ' quotient $'
	r db ' remainder $'
	a db ?
	b db ?
data ends
code segment
	start:
	mov ax,data
	mov ds,ax
	mov bp,offset sir;punem in bp offsetul sirului
	mov ax,0;initializam ax cu 0
	mov al,[bp];punem in al byteul inferior al primului word
	mov cx,lsir;in cx lungimea sirului
	repeta:
		mov ah,[bp];punem in ah byteul inferior corespunzator wordului spre care pointeaza bp
		cmp al,ah;comparam al cu ah
		ja jos;daca ah>al
			mov al,ah;al:=ah
		jos:;altfel trece mai departe
		add bp,2;bp pointeaza spre urmatorul word
	loop repeta
	mov a,al;maximul se pune in a
	
	mov bp, offset sir;bp pointeaza din nou la inceputul sirului
	inc bp;bp:=bp+1 pentru a pointa spre byteul superior
	mov ax,0;initializam ax
	mov al,[bp];punem in al bytetul superior al primului word
	mov cx,lsir;punem in cx lungimea sirului
	repeta2:
		mov ah,[bp];punem in ah byteul superior corespunzator wordului spre care pointeaza bp
		cmp al,ah;cumparam al cu ah
		jb jos2;daca al<ah
			mov al,ah;al:=ah
		jos2:;altfel trece mai departe
	add bp,2;bp pointeaza spre urmatorul word
	loop repeta2
	mov b,al;minimul se pune in b
	
	mov ax,0;initializam ax
	mov al,a;punem maximul in al
	div b;il impartim la b
	push ax;punem ax pe stiva
	mov ah,0;ramane doar catul impartirii
	mov cx,0;initializam cx
	repeta3:
		div saispe;impartim catul la 16
		push ax;punem rezultatul pe stiva
		inc cx;incrementam cx
		cmp al,0;comparam rezultatul impartirii cu 0
	jg repeta3; se repeta procedeul daca catul nu e 0

	mov bx,offset tabela;pregatim bx pentru xlat
	repeta4:
		pop ax;scoatem ax de pe stiva
		xchg al,ah;interschimbam al,ah, ne intereseaza restul din ah
		xlat tabela;transformam in caracter
		mov dl,al;il punem in dl
		mov ah,02h;apelam intreruperea pentru afisare caracter
		int 21h
	loop repeta4;cate pushuri s-au facut la repeta3 atatea popuri aici

	mov dx,offset q;afisam stringul q
	mov ah,09h
	int 21h

	pop ax;scoatem din stiva ax, care contine rezultatul lui a/b
	xchg al,ah;se interschimba ah cu al, de aceasta data ne intereseaza restul din ah
	mov ah,0;facem acelasi lucru ca si cu catul
	mov cx,0

	repeta5:
		div saispe
		push ax
		inc cx
		cmp al,0
	jg repeta5

	mov bx,offset tabela
	repeta6:
		pop ax
		xchg al,ah
		xlat tabela
		mov dl,al
		mov ah,02h
		int 21h
	loop repeta6

	mov dx,offset r
	mov ah,09h
	int 21h

	mov ah,4ch
	int 21h
code ends
end start
