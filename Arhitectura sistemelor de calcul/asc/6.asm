;6. Sa se implementeze un program de autentificare. Programul are definit in 
; segmentul de date un sir de caractere numit 'parola'. 
; Programul va cere utilizatorului sa introduca parola de la tastatura si va verifica 
; daca aceasta este identica cu sirul 'parola' din segmentul de date si va afisa un mesaj corespunzator. 
; Programul tot cere utilizatorului parola, pana cand acesta o ghiceste.

assume cs:code, ds:data, es:data
data segment
	parola db 'abcd$' ;65666768$
	len equ $-parola
	t db 'parola:$'
	maxsircitit db 100
	lsircitit db ?
	sircitit db 100 dup (?)
	new db 10,13, '$'
	b db 'parola corecta$'
data ends

code segment
start:
	mov ax, data
	mov ds,ax
	mov es,ax
	
	repeta:
		;afisez textul ,,parola:"
		mov ah, 09h
		mov dx, offset t
		int 21h
		
		;citesc de la tastatura
		mov ah, 0ah
		mov dx, offset maxsircitit
		int 21h
		
		; adaug $ la sfarsitul sirului citit de la tastatura
		mov bl, lsircitit
		mov bh,0
		mov sircitit[bx], '$'
		
		; linie noua
		mov ah, 09h
		mov dx, offset new
		int 21h
			
		; intructiunea cmpsb - compara stringuri
		cld
		mov cx, len
		mov si, offset parola
		mov di, offset sircitit
		repeta2:
			cmpsb
			jne repeta ;compar, si daca nu-s egale caracterele, pun utilizatorul sa reintroduca o noua parola
		loop repeta2 ;compar, si daca sunt egale caracterele, mai compar o data. pana se termina
		
		; daca utilizatorul a introdus parola corecta
		corect:
			; afisez linie noua
			mov ah, 09h
			mov dx, offset new
			int 21h
			
			; afisez textul ,,parola corecta"
			mov ah, 09h
			mov dx, offset b
			int 21h
		
		
mov ax, 4c00h
int 21h
	
code ends
end start

		
		