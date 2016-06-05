assume CS:code, DS:data
data segment
	saispe dw 16
	Tabhexa db '0123456789ABCDEF'
data ends
code segment
afisare proc
	cmp ax,0
	jge pozitiv
	push ax
	mov ah,02h
	mov dl,'-'
	int 21h
	pop ax
	pozitiv:
		mov cx,0
		repeta:
			mov dx,0  ; convertesc la double word
			div saispe
			push dx
			inc cx
			cmp ax,0
		jne repeta
	
	afis:
		pop dx
		mov bx,offset Tabhexa
		mov ax,dx
		xlat
		mov dx,ax
		mov ah,02h
		int 21h
	loop afis
		; afisez un spatiu intre numere
		mov dl,32
		int 21h
	ret
	afisare endp
start:
mov ax,data
mov ds,ax

	mov ax,12h
	call afisare

mov ax,4C00h
int 21h
code ends
end start