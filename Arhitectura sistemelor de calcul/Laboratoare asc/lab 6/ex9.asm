;9. Se da un sir de octeti S. Sa se construiasca un sir D1 care sa contina toate numerele ;pozitive si un sir D2 care sa contina toate numerele negative din S.
;Exemplu:
;S: 1, 3, -2, -5, 3, -8, 5, 0
;D1: 1, 3, 3, 5, 0
;D2: -2, -5, -8

assume cs:code, ds: data
data segment
	
	s db 1, 3, -2, -5, 3, -8, 5, 0
	len equ $-s ;lungimea sirului s
	d1 db len dup (?) ; sir pentru numere pozitive
	d2 db len dup (?) ; sir pentru numere negative

data ends
code segment
start:
	mov ax,data
	mov ds,ax

	mov si,offset s ;adresa de inceput a sirului s, adica 0 in cazul de fata
	mov bx,0 ; bx - contor pentru d1
	mov di,0 ; di - contor pentru d2
	mov cx,len ; cx = lungimea sirului s

	repeta: ;repeta pana cand cx devine 0
		mov al,s[si]
		cmp al,0 ;compara al cu 0
		jl nega ; daca e mai mic decat 0 sare la eticheta nega
		jge  poz ; daca e mai mare sau egal cu 0 sare la eticheta poz

		nega:	;daca elementul din al este negativ
			mov d2[di],al ; il punem in sirul d2 la pozitia di
			inc di ; incrementam di
			inc si ; incrementam si
			loop repeta ;sarim la eticheta repeta
		poz:	;daca elementul din al este pozitiv
			mov d1[bx],al ;il punem in sirul d1 la pozitia bx
			inc bx ; incrementam bx
			inc si ; incrementam s1
			loop repeta ;sarim la eticheta repeta

	mov ax, 4c00h
	int 21h
code ends
end start	