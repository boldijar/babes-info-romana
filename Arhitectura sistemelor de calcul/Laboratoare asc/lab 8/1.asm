; Laborator 8 - intreruperi
; 1. Se da un sir de octeti in segmentul de date. Sa se afiseze elementele acestui sir 
; la iesirea standard (ecran) in baza 2.

assume cs:code, ds:data
data segment
	sir db 16, 32, 33, 127, -2
	len equ $-sir
	doi dw 2 ;pentru impartirea la 2 a configuratiei dx:ax
	new db 10,13,'$' ; linie noua pe ecran
data ends

code segment

afisare proc
		mov cx,0 ; numara cate impartiri face pentru un element din sir (cate resturi avem de afisat)
		repeta:
			mov dx,0 ;pentru a putea imparti dx:ax la 2
			div doi ;impartim dx:ax la 2
			push dx ; punem restul pe stiva pentru a nu-l strica
			inc cx ; crestem cx
			cmp ax,0 ;compara catul cu 0
		jne repeta ; daca, catul nu e 0, mai impartim
		
		afis:
			pop dx ;luam restul de pe stiva
			add dl, '0' ; transformam din cifra in caracter
			mov ah,02h ; afisare de caracter
			int 21h
		loop afis
	ret
afisare endp
		
start:
mov ax, data
mov ds, ax

mov si,0 ;index pentru elementele din sir
repeta2:
	mov al, sir[si] ; pun in 'al' octetul de pe pozitia 'si' din 'sir'
	mov ah, 0 ; transformam in cuvant
	call afisare ;apelam procedura afisare, ia primul element din sir si il transforma in baza 2
	mov ah,09h ; afisare sir de caractere
	mov dx, offset new ; pune adresa labelului new, afisam linie noua pe ecran
	int 21h
	inc si ;mergem la urmatorul element din sir
	cmp si,len ;comparam cu lungimea sirului
	jb repeta2 ;daca 'si' mai mic decat lungimea sirului, sarim la repeta2

mov ax, 4c00h
int 21h
code ends
end start