ASSUME cs: code, ds:data     ;spunem asamblorului care sunt segmentele folosite de noi

 

data SEGMENT                
sir1 db 1,2,4,5,1,2,4,1,2,6,7,8
l1 equ $-sir1
sir2 db 1,2,4
l2 equ $-sir2
rez db l1 dup (?)
data ENDS


code SEGMENT                 ;code - numele segmentului de cod

start:

mov ax,data 
mov ds,ax 
mov es,ax
mov si,offset sir2
mov di,0
mov bx,l2
add bx,si
repeta:
	cmp bx,si			;compara pozitia curenta cu capatul sirului sir2
	je adauga
	lodsb 				;pune in al un element din sir2
	mov ah,sir1[di]		;pune in ah un element din sir1
	inc di				;trece la pozitia urmatoare din sir1
	cmp ah,al			;compara elementul din sir1 cu cel din sir2
	je repeta			;daca sunt egale, repeta pana cand sir2 s-a epuizat
						;daca nu sunt egale, executa urmatoarele
mov si,offset sir2		;si revine la inceputul lui sir2
cmp di,l1				;verifica daca mai sunt elemente din sir1
jne repeta				;daca da, repeta
jmp fin					;daca nu, trece la final
	
adauga:					;adauga pozitia de inceput a sirului sir2 in sir1
	mov cx,di			;pune in cx pozitia din sir1
	sub cx,l2			;scade lungimea lui sir2
	mov rez[bp],cl		;pune rezultatul in sirul rezultat
	add rez[bp],30h		;pentru o memorare convenabila
	mov cx,0			
	mov si,offset sir2	;si revine la inceputul lui sir2
	inc bp				;trecem la pozitia urmatoare in sirul rezultat
	cmp di,l1			;verificam daca mai sunt elemente in sir1
	jne repeta			;daca mai sunt, repetam
fin:
mov ax,4C00h 
int 21h 
    

code ENDS

END start