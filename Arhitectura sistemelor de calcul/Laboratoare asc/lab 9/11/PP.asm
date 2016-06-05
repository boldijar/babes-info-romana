; Laborator 9
; 11. Se citesc mai multe siruri de caractere. Sa se determine daca primul apare ca 
; subsecventa in fiecare din celelalte si sa se dea un mesaj corespunzator. 

assume cs:code, ds:data, es:data
data segment public
	
	maxLenStr db 200
	lenStr db ?
	s db 200 dup (?)
	S2 db 100 dup (?)
	len_s2 dw ?
	printMsg db "Introduceti sirurile: $"
	finalMsg db "Nu am gasit in fiecare cuvant primul string $"
	gasitMsg db "Terminat cu succes$"
	linieN db 10,13,'$'
data ends

code segment public
extrn compara:proc

; procedura pentru afisare
print proc
	;input: dx - offsetul mesajului de printat
	mov ah,09h
	int 21h
	ret
print endp

start:
	mov ax,data
	mov ds,ax
	mov es,ax ;pentru lucru cu funtiile pentru siruri
	
	; afisam mesajul "Introduceti sirurile: $"
	lea dx, printMsg
	call print
	
	; citim noul sir
	lea dx,maxLenStr
	mov ah,0Ah
	int 21h
	
	;punem de mana un spatiu la finalul sirului citit
	lea bx,s
	add bl,lenStr
	mov byte ptr [bx],32
	
	lea si,s ;pentru funciile de lucru cu siruri
	lea di, s2
	cld ;pentru a merge crescator cu functiile lodsb, stosb
	mov cx,0 ; sa calculam cate caractere are primul string
	loop1:
		lodsb ;incarca in AL caracterul de la offsetul si
		stosb ;pune in memorie la offsetul di, caracterul din AL
		inc cx
		cmp byte ptr [si],32		;cand ajungem la primul spatiu ne oprim
	jne loop1
	mov len_s2,cx
	
	cauta:
		inc si
		mov cx,len_s2	;cate caractere comparam
		lea di,s2
		; SI este deja la un incaput de cuvant inainte apelului procedurii
		call compara	;AL = 0 (nu s-a gasit)
						;AL = 1 (nu s-a gasit + am gasit spatiu)
						;AL = 2 (s-a gasit)
		;daca am ajuns la un spatiu si primul cuvant din sir nu apare in urmatorul cuvant
		cmp al,1
		je final
		
		;nu am gasit si merge mai departe in cadrul aceluiasi cuvant
		cmp al,0
		je mai_departe
		
		; am gasit primul cuvant ca subsecventa in cuvantul curent si mergem la urmatorul cuvant
		cmp al,2
		je urm_cuvant
		
		urm_cuvant:
			inc si
			cmp byte ptr [si],32
			jne urm_cuvant
		
		
	mai_departe:
		
		mov ax, si
		sub ax,offset s		;optinem pozitia curenta din sir
		cmp al,lenStr
	jb cauta
	
	;afisam o linie noua
	lea dx,linieN
	call print
	
	;afisam un mesaj cum ca primul cuvant apare ca subsecventa in toate cuvintele
	lea dx,gasitMsg
	call print
	jmp done
	
	;daca nu am gasit afisam un mesaj corespunzator
	final:
		lea dx,linieN
		call print
		lea dx,finalMsg
		call print
		
	done:
	mov ax,4c00h
	int 21h
code ends
end start