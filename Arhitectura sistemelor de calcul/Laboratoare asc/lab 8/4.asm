;4. Sa se afiseze data curenta si ziua curenta din saptamana (in litere).

assume cs:code, ds:data

data segment
	lun db ' luni$'
	mar db ' marti$'
	mie db ' miercuri$'
	joi db ' joi$'
	vin db ' vineri$'
	sam db ' sambata$'
	dum db ' duminica$'
	
	zi db 2 dup(?), '/$'
	luna db 2 dup(?), '/$'
	an db 4 dup(?), '$'
	
	zece db 10
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	mov ah, 2Ah
	int 21h
	;al- ziua (duminica, luni, marti...) (0-6)
	;cx - anul
	;dh - luna
	;dl - ziua (1-31)
	
	mov bl, al
	
	mov ax, cx
	
	div zece
	add ah, '0'
	mov an[3], ah
	mov ah,0
	
	div zece
	add ah, '0'
	mov an[2], ah
	mov ah,0
	
	div zece
	add ah, '0'
	mov an[1], ah
	mov ah,0
	
	div zece
	add ah, '0'
	mov an[0], ah
	mov ah,0
	
	mov al, dh
	mov ah, 0
	div zece
	add ah, '0'
	mov luna[1], ah
	add al, '0'
	mov luna[0], al
	
	mov al,dl
	mov ah,0
	div zece
	add ah,'0'
	mov zi[1], ah
	add al,'0'
	mov zi[0], al
	
	mov ah,09h
	mov dx, offset zi
	int 21h
	mov dx, offset luna
	int 21h
	mov dx, offset an
	int 21h
	
	
	mov ah, 09h
	
	cmp bl,0
	ja et1
	mov dx, offset dum
	int 21h
	jmp final
	
	et1:
		cmp bl,1
		ja et2
		mov dx, offset lun
		int 21h
		jmp final
	
	et2:
		cmp bl,2
		ja et3
		mov dx, offset mar
		int 21h
		jmp final
	
	et3:
		cmp bl,3
		ja et4
		mov dx, offset mie
		int 21h
		jmp final
	
	et4:
		cmp bl,4
		ja et5
		mov dx, offset joi
		int 21h
		jmp final
	et5:
		cmp bl,5
		ja et6
		mov dx, offset vin
		int 21h
		jmp final
	
	et6:
		mov dx, offset sam
		int 21h
	
	final:
		mov ax, 4c00h
		int 21h

code ends
end start
