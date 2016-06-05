; Sa se stearga un fisier al carui nume este introdus de la tastatura.

assume cs:code, ds:data
data segment
	numefis db 10,?,10 dup (?)
	msg1 db 'Stergerea s-a facut cu succes','$'
	msg2 db 'A aparut o eroare la stergere!','$'
data ends

code segment
start:
	push data
	pop ds
	
	mov ah,0Ah
	mov dx,offset numefis
	int 21h
	mov bl,numefis[1]
	mov bh,0
	mov numefis[bx+2],0
	mov ah,41h
	mov dx,offset numefis+2
	int 21h
	jc eroare
	mov ah,09h
	mov dx,offset msg1
	int 21h
	jmp final
	
	eroare:
		mov ah,09h
		mov dx,offset msg2
		int21h
		
	final:
		mov ax,4c00h
		int21h
code ends
end start