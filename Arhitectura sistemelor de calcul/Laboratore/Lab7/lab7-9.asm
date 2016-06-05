;9. Dandu-se un sir de dublucuvinte, sa se obtina un alt 
;sir de dublucuvinte in care se vor pastra doar 
;dublucuvintele din primul sir care au un numar par de 
;biti cu valoare 1.

assume ds: data, cs:code
data segment
	sir1 dd 01h, 12300011h, 0abcd0h, 2218acach, 7a082ae3h
	l EQU ($-sir1)/4
	sir2 dd l dup(?)
	doi db 2h
	aux1 dw ?
	aux2 dw ?
data ends
code segment
start:
	mov ax, data
	mov ds, ax

	mov cx, l ;pune in cx lungimea lui sir1
	mov si, offset sir1 ;in ds:si punem adresa (far a) sirului sir1
	mov ax, seg sir1
	mov ds, ax
	mov di, offset sir2
	mov ax, seg sir2
	mov es, ax
	cld ;parcurgem sirul de la stanga la dreapta (DF=0).
	repeta_sir:
		lodsw ;pune in ax, ds:si
		mov dx, ax ;pune in dx partea low
		lodsw ; pune in ax partea high
		mov aux1, ax ;pune in aux1 partea high
		mov aux2, ax ;pune in aux2 partea high
;folosim aux2:dx

		mov ax, 0 ;numarul de biti 1
		mov bh, 0 ; contor pentru repeta
		repeta:
		mov bl, 0 ; contor pentru repeta1
			repeta1:
				rcl aux1,1
				adc al, 0 ;adunam fiecare bit din cary flag, respectiv aux1
				inc bl
				cmp bl, 16 ;rotim de 16 ori pentru ca avem word
			jne repeta1
		mov aux1, dx ;pune in aux1 partea low
		inc bh
		cmp bh, 2; trebuie sa mearga de doua ori prin repeta pentru ca ii dublu cuvant
		jne repeta
		div doi ;verificam daca al ii divizibil cu 2
		cmp ah, 0
		jnz urmatorul ;daca nu ii divizibil cu doi sare la urmatorul, putem pune si jne

		mov ax, dx ;punem partea low in ax
		stosw ;pune in ES:DI, ax ; punem in ES:DI partea low
		mov ax, aux2 ;pune in ax, aux2 ; punem in ax partea high
		stosw ;pune in ES:DI, ax ;punem partea high in ES:DI

	urmatorul:
		loop repeta_sir ;sare la repeta_sir daca mai sunt dublucuvinte neverificate

	mov ax, 4c00h
	int 21h
code ends
end start