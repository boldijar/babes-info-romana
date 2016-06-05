; se citeste un caracter si un nume de fisier, sa se caute in fisier caracterul si sa se 
; afiseze pe ecran pozitia unde a fost gasit prima oara

assume cs:code, ds:data

data segment
	maxnumefis db 15
	lfis db ?
	numefis db 15 dup(?)
	nu db 'Nu e gasit$'
	buffer db 200 dup(?)
	poz dw ?,'$'
data ends

code segment
start:
	mov ax, data
	mov ds,ax
	
	;citim numele fisierului
	mov ah,0ah
	mov dx, offset maxnumefis
	int 21h
	
	;citim caracterul
	mov ah, 01h
	int 21h
	; al - caracterul
	mov bl, al
	mov bh, 0
	
	push bx
	
	;asciiz
	mov al, lfis
	mov ah,0
	mov si, ax
	mov numefis[si], 0
	
	;deschidere fisier
	mov ah, 3dh
	mov al,0
	mov dx, offset numefis
	int 21h
	mov bx, ax
	
	;citim din fisier
	mov ah, 3fh
	mov cx, 200
	mov dx, offset buffer
	int 21h
	;ax - numarul de biti citit
	
	mov si,0
	mov cx,ax
	pop bx
	repeta:
		;comparam fiecare caracter din fisier cu caracterul citit
		mov al, buffer[si]
		mov ah,0
		cmp ax,bx
		je gasit
		add si,1
		loop repeta
	nuegasit:
		mov ah, 09h
		mov dx,offset nu
		int 21h
		jmp final
	gasit:
		mov ah, 09h
		add si,1
		mov poz, si
		mov dx, offset poz
		int 21h
	
	final:
	mov ax,4c00h
	int 21h
code ends
end start