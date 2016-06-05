assume cs:code, ds:data
data segment
	linienoua db 10,13,'$'
	mesaj     db 'In ce baza doriti afisarea?',10,13,9,'a.Baza 2',10,13,9,'b.Baza 10',10,13,9,'c.Baza 16',10,13,'$'
	zece      dw 10
	tabela    db '0123456789ABCDEF'
data ends

code segment
;urmeaza procedura care face afisarea in baza 2

AfisareBaza2 proc
	mov bx,ax            ;salvam ax pt a il utiliza in operatiile urmatoare care impun folosirea lui
	mov cx,16
	repeta2:
		shl bx,1
		jc unu          ; daca CF=1 atunci se face salt la o eticheta unde se va face afisarea caracterului '1',altfel inseamna ca CF=0 deci afisam caracterul '0'
		mov ah,02h
		mov dl,'0'
		int 21h
	loop repeta2         ;bucla se executa de cx ori, adica 16 ori
	jmp EndAfis2
	unu:
		mov ah,02h
		mov dl,'1'
		int 21h
	loop repeta2
	EndAfis2:
		ret     		;scoate din stiva adresa de revenire si face salt la acea adresa (se intoarce la instructiunea imediat urmatoare apelului functiei)
AfisareBaza2 endp
		
;In cazul afisarii unei valori in baza 10, trebuie sa facem distinctia intre ax continand un nr negativ si ax continand un nr pozitiv.
;pozitiv: prin impartiri succesive la 10
;negativ: obtinerea valorii absolute a numarului folosind instructiunea neg, urmata apoi de impartiri succesive la 10

AfisareBaza10 proc
		cmp ax,0
		jge pozitiv
		negativ:
			neg ax 		;vom obtine modulul nr negativ
			mov dl,'-'
			mov ah,02h
			int 21h
		pozitiv:
			mov cx,0
			repeta10:
				mov dx,0   ;extindem cuvantul la dublucuvant pt a evita urmatoarea situatie: 3000:10=300>255 => 'Divide by zero' (pt ca este pozitiv facem conversie fara semn)
				div zece   ;catul se obtine in ax si restul in dx
				push dx    ;push dl incorect pt ca stiva este organizata pe cuvinte
				inc cx
				cmp ax,0
			jne repeta10
		RepetaAfis:
			pop dx
			add dl,'0'     ;<=> mov dl,48, generam codul ASCII al caracterului
			mov ah,02h
			int 21h
		loop RepetaAfis
	ret
AfisareBaza10 endp

;Stim ca fiecarui grup de 4 biti de reprezentarea binara a unui numar, ii corespunde o cifra hexa, pornim de la acest principiu

AfisareBaza16 proc
	mov cx,4
	repeta16:
		mov dx,0    ;registrul folosit pt izolarea a cate unui grup de 4 biti
		push cx     ;este nevoie de el si in urmatoarea bucla
		mov cx,4
		repeta4:
			rol ax,1
			rcl dx,1
		loop repeta4
		pop cx 
		push ax
		mov al,dl
		mov bx,offset tabela       ;pt ca xlat sa poata folosi tabela de la adresa ds:bx
		xlat tabela
		mov dl,al
		mov ah,02h
		int 21h
		pop ax
	loop repeta16
  ret
 AfisareBaza16 endp
 
 start:
	push data
	pop ds
	
	mov ax,10
	push ax
	mov ah,09h
	mov dx,offset mesaj  ;<=> lea dx,mesaj
	int 21h
	mov ah,08h
	int 21h
	
	cmp al,'a'
	jne VerifB
	pop ax
	call AfisareBaza2
	jmp final
	
	VerifB:
		cmp al,'b'
		jne VerifC
		pop ax
		call AfisareBaza10
		jmp final
	
	VerifC:
		cmp al,'c'
		jne final
		call AfisareBaza16
	
	final:
		mov ah,09h                  ;dupa afisarea nr, indiferent de baza, se va afisa o linie noua
		mov dx, offset linienoua
		int 21h
		
		mov ax,4c00h
		int 21h
code ends
end start