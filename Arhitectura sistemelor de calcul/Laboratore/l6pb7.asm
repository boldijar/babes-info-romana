;7. Se da un sir de octeti S. Sa se construiasca sirul D1 ce contine elementele de pe pozitiile pare din S si sirul D2 ce contine elementele de pe pozitiile impare din S.
;Exemplu:
;S: 1, 5, 3, 8, 2, 9
;D1: 1, 3, 2
;D2: 5, 8, 9

assume cs:code, ds:data
data segment
	s db 1,5,3,8,2,9
	l EQU $-s
	d1 db l/2+1 dup (?)
	d2 db l/2+1 dup (?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax

	mov si, 0
	mov bp, 0
	mov di, 0
	repeta:
		mov al, byte ptr s[si] ; pune in al bytul de la adresa si din sirul s
		mov bx, si ; pune ax pozitia pe care ne aflam in sirul s
		and bx, 1b ; 
		cmp bx, 0                                                                 
		je par
		mov d2[bp], al
		inc bp
		jmp final
		
	par:
		mov d1[di], al
		inc di

	final:
		inc si
		cmp si, l
		jne repeta

	mov ax, 4c00h
	int 21h
code ends
end start

	

	
