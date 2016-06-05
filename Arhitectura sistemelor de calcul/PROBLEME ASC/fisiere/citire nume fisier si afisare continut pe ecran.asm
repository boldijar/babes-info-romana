assume cs:code, ds:data
data segment
		mesaj	db	'Numele fisierului:','$'
		numefis	db	12,?,12 dup(?)
		temp	db	100 dup(?),'$'
		EroareDeschidere	db	'Fisierul nu exista!','$'
		EroareCitire		db	10,13,'Nu se poate citi din fisier',10,13,'$'
data ends

code segment
start:
	push data
	pop ds
	
	mov ah,09h
	mov dx,offset mesaj		;afisam sirul de caractere mesaj
	int 21h
	
	mov ah,0Ah
	mov dx,offset numefis
	int 21h
	
	mov bl,numefis[1]
	xor bh,bh
	mov numefis[bx+2],0
	
	mov ah,3Dh				;deschidem fisierul pt citire cu functia 3Dh 
	mov al,0
	mov dx,offset numefis+2
	int 21h
	jc eteroaredeschidere
	mov bx,ax  				;daca nu am avut eroare la deschidere, salvam identificatorul fisierului in registrul bx
	
	Bucla:
		mov ah,3Fh
		mov dx,offset temp  ;offset-ul sirului in care vom citi pe rand siruri de maxim 100 caractere din fisier
		mov cx,100			;citim maxim 100 de caractere
		int 21h
		jc eteroarecitire
		mov si,ax
		mov temp[si],'$'
		mov ah,09h
		int 21h
		
		cmp si,100
		je Bucla			;daca am citi 100 de octeti inseamna ca nu am terminat de citit
		jmp inchiderefisier
		
	eteroaredeschidere:
		mov ah,09h
		lea dx,EroareDeschidere
		int 21h
		jmp final
	
	eteroarecitire:
		mov ah,09h
		lea dx,EroareCitire
		int 21h
	
	inchiderefisier:
		mov ah,3Eh
		int 21h
	
	final:
		mov ax,4C00h
		int 21h

code ends
end start
	
	