;Sa se citeasca de la tastatura doua nume de fisiere. Sa se copieze
; primul fisier in cel de-al doilea. Se va semnala orice situatie de eroare.

assume cs:code,ds:data

data segment
	file1 db 10 dup(?)
	file2 db 10 dup(?)
	f1nf db 'File 1 not found.',13,10,'$'
	f2nf db 'File 2 not found.',13,10,'$'
	p1nf db 'Path 1 not found.',13,10,'$'
	p2nf db 'Path 2 not found.',13,10,'$'
	ac1d db 'Acces to file 1 denied.',13,10,'$'
	ac2d db 'Acces to file 2 denied.',13,10,'$'
	buffer db 30 dup(?)
	mesaj1 db 'Dati numele primului fisier: ',13,10,'$'
	mesaj2 db 'Dati numele celui de-al doilea fisier: ',13,10,'$'
	nbr dw ?
	nbw dw ?
data ends

code segment
	start:
		mov ax,data
		mov ds,ax
		mov si,0

		mov ah,09h
		mov dx,offset mesaj1
		int 21h
		mov ah,01h
		int 21h
		
		bucla1:
			mov file1[si],al
			inc si
			int 21h
			cmp al,13
			je sf1
		jmp bucla1
	
		sf1:
			mov file1[si],0

		mov si,0
		mov ah,09h
		mov dx,offset mesaj2
		int 21h
		mov ah,01h
		int 21h

		bucla2:
			mov file2[si],al
			inc si
			int 21h
			cmp al,13
			je sf2
		jmp bucla2

		sf2:
			mov file2[si],0

; deschidem fisierul 1 pentru citire
		mov ah,3dh
		mov al,0;cu 0 accesam pt citire
		mov dx,offset file1
		int 21h
		jc openerror1
		mov bx,ax ; salvam identificatorul fisierului in bx

; citim din fisier si salvam in buffer
		goon1:
			mov ah,3fh
			mov cx,30 ;citim maxim 30 de caractere
			mov dx,offset buffer
			int 21h
			jc readerror
;mov nbr,ax ;nbr=number of bytes read
;cmp nbr,30
;je goon1

; deschidem fisierul 2 pt scriere
			mov ah,3dh
			mov al,00000001b
			mov dx,offset file2
			int 21h
			jc openerror2
			
			mov bx,ax ; salvam identificatorul fisierului in bx
; scriem in fisier ce avem in buffer
			goon2:
				mov ah,40h
				mov cx,30 ;scriem maxim 30 de caractere
				mov dx,offset buffer
				int 21h
				jc writeerror
;mov nbw,ax ;nbw=number of bytes written
;cmp nbw,30
;je goon2

			jmp sf

			openerror1:
				cmp ax,2
				je file1nf
				cmp ax,2
				je path1nf
				cmp ax,5
				je acces1d
				jmp sf

			openerror2:
				cmp ax,2
				je file2nf
				cmp ax,2
				je path2nf
				cmp ax,5
				je acces2d
				jmp sf

			readerror:
				cmp ax,5
				je acces1d
				jmp sf

			writeerror:
				cmp ax,5
				je acces2d
				jmp sf

			file1nf:
				mov ah,09h
				mov dx,offset f1nf
				int 21h
				jmp sf

			file2nf:
				mov ah,09h
				mov dx,offset f2nf
				int 21h
				jmp sf

			path1nf:
				mov ah,09h
				mov dx,offset p1nf
				int 21h
				jmp sf

			path2nf:
				mov ah,09h
				mov dx,offset p2nf
				int 21h
				jmp sf

			acces1d:
				mov ah,09h
				mov dx,offset ac1d
				int 21h
				jmp sf

			acces2d:
				mov ah,09h
				mov dx,offset ac2d
				int 21h
				jmp sf

			sf:
				mov ax,4C00h
				int 21h
code ends
end start

