;2. Sa se citeasca cate un caracter de la tastatura, fara ecou.
; Daca este cifra, sa se tipareasca pe ecran, daca este caracterul '$', se termina programul, 
; in orice alta situatie se adauga caracterul intr-un buffer care se va tipari in final pe ecran.

assume cs:code, ds:data
data segment
	sir db 100 dup(?)
	new db 10,13, '$'
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	mov si, 0
	
	mov ah, 08h
	int 21h
	; al - caracterul
	
	repeta:
		cmp al, '$'
		je final
	
		cmp al, '9'
		ja et
		cmp al, '0'
		jb et
	
		; daca ajungem aici, inseamna ca avem cifra si o afisam
		mov ah, 02h
		mov dl, al
		int 21h
		
		jmp et1 ;sarim la et1 pentru a mai citi un caracter
		
		et:
			; daca nu e cifra
			mov sir[si], al
			add si,1
		
		et1:
			mov ah, 08h
			int 21h
			jmp repeta
		
	final:
	mov sir[si], al

	mov ah, 09h
	mov dx, offset sir
	int 21h
	
	mov ax, 4c00h
	int 21h
code ends
end start