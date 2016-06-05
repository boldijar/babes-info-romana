;16. Sa se citeasca de la tastatura numele unui fisier. Sa se verifice daca dimensiunea fisierului este multiplu de 13,
; si in caz negativ sa se completeze fisierul cu un numar minim de octeti 0 astfel incat dimensiunea fisierului sa devina multiplu de 13. 

assume cs:code, ds:data

data segment
	mesaj1 db 'Dati numele fisierului: $' 13,10
	citiresir db 20,?,20 dup(?)
	rest db 13 dup (0)

data ends

code segment
start:
	mov ax, data
	mov ds, ax

	mov ah, 09h
	mov dx, offset mesaj1
	int 21h                 ;afisez mesajul de intrare

	mov ah, 0Ah
	mov dx, offset citiresir
	int 21h                 ;citesc numele fisierului
	mov bx, offset citiresir+1
	mov citiresir[bx+1+2],'$'

	mov ah, 3dh
	mov al, 2h
	mov dx, offset citestesir+2	
	int 21h                 ;deschid fisierul deschis (pune in ax indicativul numelui fisierului)

	
	mov ah,42h
	mov bx, ax
	mov dx, 0
	mov cx, 0
	mov al, 2
	int 21h			;calculez dimensiunea fisierului (in DX:AX se pune dimensiunea)

	mov cx, 13              ;convertesc 13 la word
	div cx
	cmp dx, 0
	jne conversie
	je final

	conversie:
		sub dx,cx

		mov ax, 40h
		mov cx, dx
		mov dx, offset rest
		int 21h
	final:
	mov ax, 4c00h
	int 21h
code ends
end start