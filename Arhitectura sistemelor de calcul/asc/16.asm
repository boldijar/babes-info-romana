;16. Sa se citeasca de la tastatura numele unui fisier. Sa se verifice daca dimensiunea 
;fisierului este multiplu de 13, si in caz negativ sa se completeze fisierul cu un numar 
;minim de octeti 0 astfel incat dimensiunea fisierului sa devina multiplu de 13.

assume cs:code, ds:data
data segment
	msg db 'Numele fisierului: $'
	maxFileName db 13
	lFileName db ?
	fileName db 20 dup(?)
	trei db 13
	gata db 'gata$'
	zero db '0'
data ends

code segment
start:
	mov ax, data
	mov ds,ax
	
	;afisam mesajul ,,Numele fisierului: "
	mov ah,09h
	mov dx, offset msg
	int 21h
	
	;citim de la tastatura numele fisierului
	mov ah, 0ah
	mov dx, offset maxFileName
	int 21h
	
	;transformam numele fisierului intr-un string asciiz
	mov al, lFileName
	mov ah,0
	mov si, ax
	mov fileName[si], 0
	
	;deschidem fisierul
	mov ah, 3dh
	mov al, 2
	mov dx, offset fileName
	int 21h
	;ax - file handle
	
	;citim caractere din fisier, toate caracterele insemnand numarul de octeti
	mov bx, ax
	mov ah, 3fh
	mov cx, 200
	mov dx, offset fileName
	int 21h
	;ax - numarul de biti citit
	
	div trei
	cmp ah,0
	jne nuemultiplu
	jmp final
	nuemultiplu:
		mov dx, 13
		mov al, ah
		mov ah,0
		sub dx, ax
		
		mov cx,dx
		mov si,0
		repeta2:
		    push cx
			mov cx,1
			mov dx, offset zero
			mov ah,40h
			int 21h
			add si,1
			pop cx
			cmp si,cx
			jne repeta2
	final:
	
	mov ah, 09h
	mov dx, offset gata
	int 21h
	
	mov ax, 4c00h
	int 21h
code ends
end start