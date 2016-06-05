;15. Se da un sir de cuvinte. Sa se construiasca doua siruri de octeti, s1 si s2, astfel: pentru fiecare cuvant, 
;- daca numarul de biti 1 din octetul high al cuvantului este mai mare decat numarul de biti 1 din octetul low, atunci s1 
;va contine octetul high, iar s2 octetul low al cuvantului 
;- daca numarul de biti 1 din cei doi octeti ai cuvantului sunt egali, atunci s1 va contine numarul de biti 1 din octet, ;iar s2 valoarea 0 
;- altfel, s1 va contine octetul low, iar s2 octetul high al cuvantului.

assume cs: code, ds: data
data segment
	
	sir dw 0301h, 0202h, 0107h
	l EQU $-sir
	s1 db l dup(?)
	s2 db l dup(?)
	aux1 dw ?
	aux2 dw ?

data ends
code segment
start:
	mov ax, data
	mov ds, ax
	mov es, ax
	mov si, offset sir
	mov di, offset s1
	mov aux1, di
	mov di, offset s2
	mov aux2, di
	mov cx, l
	cld
	repeta:
		cmp si, l
		je finish
		mov di, 0
		mov dx, 0
		lodsw
		mov bx, ax
		repeta1:
			rcl bl, 1
			adc dh, 0
			rcl bh, 1
			adc dl, 0
			inc di
			cmp di, 8
		jne repeta1
		cmp dh, dl
		ja lowtos1
		jb hightos1
		je unutos1

	hightos1:
		mov di, aux2
		stosb ;pune din al, in es:di (adica in sirul s2)
		mov aux2, di
		mov al, ah
		mov di, aux1
		stosb ;pune din al, in es:di (adica in sirul s1)
		mov aux1, di
		jmp repeta

	lowtos1:
		mov di, aux1
		stosb ;pune din al, in es:di (adica in sirul s1)
		mov aux1, di
		mov al, ah
		mov di, aux2
		stosb ;pune din al, in es:di (adica in sirul s2)
		mov aux2, di
		jmp repeta

	unutos1:
		mov al, dl
		add al, dh
		mov di, aux1
		stosb ;pune din al, in es:di (adica in sirul s1)
		mov aux1, di
		mov al, 0
		mov di, aux2
		stosb ;pune din al, in es:di (adica in sirul s2)
		mov aux2, di
		jmp repeta

	finish:
		mov ax, 4c00h
		int 21h

code ends
end start