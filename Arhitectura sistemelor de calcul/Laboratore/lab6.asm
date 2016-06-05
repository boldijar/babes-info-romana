;7. Se da un sir de octeti S. Sa se construiasca 
;sirul D1 ce contine elementele de pe pozitiile pare din S si 
;sirul D2 ce contine elementele de pe pozitiile impare din S.
;Exemplu:
;S: 1, 5, 3, 8, 2, 9
;D1: 1, 3, 2
;D2: 5, 8, 9

assume cs:code , ds:data
data segment 
	s db 1,5,3,8,2,9
	l EQU $ - s
	d1 db l dup (?)
	d2 db l dup (?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov si,offset s
	mov di,0
	mov bp,0
	cld
	repeta:
	    mov al,s[si]
		mov bx,si
		and bl,1b
		cmp bl,0
		je par
		mov d1[di],al
		inc di
		jmp final
	par:
		mov d2[bp],al
		inc bp
		
	final:
		inc si
		cmp si,l
		jne repeta
	mov ax,4c00h
	int 21h
code ends 
end start	
		
		