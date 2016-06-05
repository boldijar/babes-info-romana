;problema 20. se citeste de la tastatura un nume de subdirector. sa se creeze in directorul
; curent un subdirector cu numele citit si apoi sa se stearga.

assume cs:code, ds:data

data segment
	maxfilename db 20
	lfilename db ?
	filename db 30 dup(?)
	numesub db 'nume subdirector: $'
	currentdir db 200 dup (?), '$'
	nuegasit db 'subdirectorul nu a fost gasit$'
	egasit db 'subdirectorul a fost sters$'
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	;afisam ,,nume subdirector
	mov ah, 09h
	mov dx, offset numesub
	int 21h
	
	;citim numele directorului de la tastatura
	mov ah,0ah
	mov dx, offset maxfilename
	int 21h
	
	;transformam numele fisierului intr-un string asciiz
	mov al, lfilename
	mov ah,0
	mov si, ax
	mov filename[si], 0
	
	
	;get current directory
	mov ah, 47h
	mov dl, 26
	mov si, offset currentdir
	int 21h
	
	;create directory
	mov ah, 39h
	mov dx, offset filename
	int 21h
	
	;setam carry flag la 1, sa putem aveam in ax erorile de la stergere
	stc
	
	;delete directory
	mov ah, 3AH
	mov dx, offset filename
	int 21h
	;ax - erori(3,5,16) sau FFFF daca nu sunt erori
	
	cmp ax, 0FFFFh
	je gasit
	
	mov ah, 09h
	mov dx, offset nuegasit
	int 21h
	jmp final
	
	gasit:
	mov ah, 09h
	mov dx, offset egasit
	int 21h
	
	final:
	mov ax, 4c00h
	int 21h
code ends
end start