;Sa se afisese in baza 10 continutul reg ax si bx

assume cs:code, ds:data
data segment
  zece dw 10
data ends
code segment
	afisare proc ;afiseaza cont lui AX
		cmp ax,0
		jge pozitiv
		push ax
		mov al, 02h
		mov dl,'-'
		int 21h
		pop ax
		neg ax ;schimba semnul
		
		pozitiv:
			mov cx,0
			repeta:
				mov dx,0
				div zece
				push dx
				inc cx
				cmp ax,0
			jne repeta
		afis:
			pop dx
			mov ah,02h
			add dl,48
			int 21h
		loop afis
	ret
	afisare endp
start:
	push data
	pop ds
	mov ax,-125
	mov bx,1027
	call afisare

	mov ax,4cooh
	int 21h
code ends
end start