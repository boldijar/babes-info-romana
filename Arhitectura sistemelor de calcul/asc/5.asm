;5. Sa se afiseze ora sistem curenta sub forma hh:mm si sa se specifice cu sirul
; 'AM' sau 'PM' daca este antemeridian sau postmeridian.

assume cs:code, ds:data

data segment
	am db ' AM$'
	pm db ' PM$'
	hh db 2 dup(?), ':$'
	mm db 2 dup(?), '$'
	t db ?
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	mov ah,2Ch
	int 21h
	;ch - ora(0-23)
	;cl - minute(0-59)
	
	mov al, cl
	mov ah,0
	mov bl,10
	div bl
	add ah, '0'
	mov mm[1], ah
	add al, '0'
	mov mm[0], al
	
	mov al, ch
	mov ah,0
	mov bl,10
	div bl
	add ah, '0'
	mov hh[1], ah
	add al, '0'
	mov hh[0], al
	
	mov ah, 09h
	mov dx, offset hh
	int 21h
	mov dx, offset mm
	int 21h
	
	mov al,ch
	mov ah,0
	mov bl,12 ;pentru verificare am sau pm
	div bl
	mov t, ah ; pun catul in t, 0(am), 1(pm)
	
	cmp t,0
	je anti
	mov ah, 09h
	mov dx, offset pm
	int 21h
	jmp final
	
	anti:
		mov ah, 09h
		mov dx, offset am
		int 21h
	
	final:
		mov ax, 4c00h
		int 21h
		
code ends
end start
