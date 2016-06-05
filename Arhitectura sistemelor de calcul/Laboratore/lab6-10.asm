ASSUME CS:code,DS:data,ES:data
data segment
	s db 1,4,2,4,8,2,1,1	;sirul initial de osteti - aceasta intructiune aloca cate un octet 
							;pt fiecare caracter din sir in ordinea in care acestea apar
	L EQU $-s				;lungimea sirului
	d db L dup (?)			;alocam spatiu pt sirul rezultat d, care va avea aceeasi lungime ca si s;
							;operatoril DUP se foloseste pt rezervarea unui bloc de memorie de lungime L 

data ends

code segment
	start:
	mov ax,data
	mov ds,ax
	
	mov es,ax		;incarcam in es adresa de inceput a 
					;segmentului in care se afla sirul destinatie d, adica tot segmentul data
	mov si,offset s	;in registrul index si retinem offset-ul sirului s
	mov di,offset d	;in registrul index di retinem offset-ul sirului d; di=8 
	mov cx,L-1		;cx=8
	jcxz sfarsit	;daca cx=0 atunci sare la sfarsit
	cld			;stabilesc directia de parcurgere a sirului de la stanga spre dreapta, 
				;crescator prin setarea la 0 a valorii flagului de directie DF=0 ,parcurg sirul de la 0
	lodsb		;incarcam in registrul al = octetul de la ds:si (aici se afla sirul s)
				;si trecem la urmatorul octet din sirul sursa, prin cresterea valorii lui si cu 1(datorita directiei de parcurgere a sirului)
	stosb		; in es:di pune octetul din al; copiem valoarea din al la adresa es:di(se aflsa d) 
				;si trecem la urmatorul ostet din sirul destinatie, prin cresterea valorii lui di cu 1
	
	repeta:
		lodsb	;retinem in al = octetul de la ds:si
		mov bx,di	;in bx salvez offset-ul curent din d,fiindca di il modific pentru repeta_interior
		mov di,offset d		;vreau sa incep sa verific in d 			
			repeta_interior:
				scasb		;comparam valoarea lui al cu octetul de la adresa es:di 
							;setand flagurile corespunzator rezultatelor compararii, di fiind incrementat deoarece valoarea flag-ului de directie este 0 
				je et_repeta	;daca al e deja in sir ies la loop_repeta
				cmp di,bx	;compar pe di cu bx sa vad daca am terminat elementele din d
			jb repeta_interior	;daca nu,repeta_interior
		mov di,bx			;mut in di pe bx,adica dimensiunea curenta a sirului d
		stosb				;adaug pe al la es:di
			
		et_repeta:
	loop repeta		;loop_repeta
		
	
	sfarsit:	; terminare programului
	mov ax,4C00h
	int 21h
	code ends
	end start
	