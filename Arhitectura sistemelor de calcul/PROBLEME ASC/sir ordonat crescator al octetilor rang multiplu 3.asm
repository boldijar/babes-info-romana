; Se da un sir de dublucuvinte. Sa se obitina sirul ordonat crescator al octetilor (considerati cu semn) de rang multiplu de 3 (in memorie).
; Ordonarea sa se faca prin interclasare.

assume cs:code, ds:data
data segment
	s	dd	12345678h, 5A5FEh, 13245768h
	l	equ	$-s
	d	db	l/3+1 dup(?)
data ends

code segment
	Insereaza proc
			push di
			push cx
			cmp di,offset d
			je adauga
			std
			mov cx di
			sub cx,offset d
			dec di
			
			repeta1:
				scasb  ;compara octetul din al cu octetul de la adresa es:di si dec di pt ca DF=1
				jge dlplus2
				mov bl,byte ptr es:[di+1]
				mov byte ptr es:[di+2],bl
			loop repeta1
			
			jmp dlplus1
			
			dlplus2:
				inc di
			
			dlplus1:
				inc di
			
			adauga:
				stosb
			
			pop cx
			pop di
			inc di ;pt ca am adaugat un element
			cld
		ret
	Insereaza endp
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	mov ax,l
	mov bx,3
	div bl
	cmp ah,0
	je et1
	inc al
	et1:
		mov si,offset s
		mov di,offset d
		cld
		mov cl,al
		xor ch,ch
		jcxz final
		repeta:
			lodsb ; ds:si -> al 
			call Insereaza
			lodsw           ;ignoram urmatorii 2 octeti
		loop repeta
	final:
		mov ax,4c00h
		int 21h
code ends
end start