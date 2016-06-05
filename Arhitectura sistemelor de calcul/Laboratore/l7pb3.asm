;3. Se da un sir de dublucuvinte.
;Sa se ordoneze crescator sirul cuvintelor superioare ale acestor dublucuvinte.
;Cuvintele inferioare raman neschimbate.
;Ex: dandu-se: sir DD 12AB5678h 1256ABCDh, 12344344h
;rezultatul va fi 12345678h 1256ABCDh, 12AB4344h. 

ASSUME cs:code, ds:data

data SEGMENT
 sir DD 12AB5678h, 1256ABCDh, 12344344h
 l EQU ($-sir) /4 ;lugimea sirului exprimata in dublucuvinte
 sir2 dw l DUP(?) ;va contine cuvintele superioare din dublucuvinte in scopul sortarii lor
data ends

code SEGMENT
start:
  mov ax,data
  mov ds,ax
  mov es,ax ; pt modificarea sirului initial  
  mov si, OFFSET sir
  mov di, OFFSET sir2	;indexul destinatie adresa de inceput a lui sir2 3*32=96
  cld ;DF=0 parcurgere de la stanga la dreapta
  mov cx,l
  jcxz sfarsit ;altfel s-ar executa de 65535
  repeta:
    lodsw ;incarca cuvantul inferior in AX
    lodsw ;incarca cuvantul superior in Ax
    stosw ;muta cuvantul superior in sir2
  loop repeta ; dec cx, cmp cx,0 ,jne repeta
  mov dx, 1 ; echivalentul unuui ok<-true pt BubbleSort
  repeta2:
	cmp dx, 0 ; echivalentul unui ok=false ?
	je mutare ; sirul este sortat crescator, nu se mai modifica nimic
	mov si, OFFSET sir2 ; adresa de inceput a lui sir2 se afla in si
	mov dx, 0 ; vom face o schimbare deci sirul nu este sortat
	mov cx, l-1 ; BubbleSort pp cel mult n-1 comparari
	repeta3:
	 mov ax, word ptr ds:[si]
	 cmp ax, word ptr ds:[si+2]
	 jle iteratie_noua ;comparatie cu semn
	 mov bx, word ptr ds:[si+2]
	 mov word ptr ds:[si], bx
	 mov word ptr ds:[si+2],ax
	 mov dx, 1
	 iteratie_noua:
	  add si, 2
	loop repeta3
  jmp repeta2
mutare:    ;se muta din sir2 cuvintele sortate in pozitiile de unde au fost luate.
    mov cx, l
	cld ;DF=0 parcurgere de la stanga la dreapta
	mov si, OFFSET sir2
	mov di, OFFSET sir+2
	muta:
	movsw
	add di,2
	loop muta
sfarsit: 
mov ax,4c00h
int 21h
code ENDS
END start