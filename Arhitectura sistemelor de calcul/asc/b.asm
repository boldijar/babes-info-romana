assume cs:code, ds:data
data segment
	a db 03h, 00h, 00h, 0feh, 0ffh, 04h, 00h, 05h, 00h
	
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	mov bx, 02 lt 20
	lea bx, [bx+2]
	mov bx, [bx+2]
	;mov es, [es+2]     es - extrasegment, nu intra in formula de calcul a offsetului
	les bx, [bx+2]
	mov bx, bx[2]
	;les bx, word ptr [bx+2]  les lucraza cu double word, si noi am pus word intr-un mod explicit
	;mov bx, bx+2		operatorii lucreaza cu valori determinabile la momentul asamblarii
	mov bl, 2[bx]
	mov es:[bx], bx
	
	;mov es:[bx], ds:[bx]
	;mov es:bx, dword ptr [bx]
	xor si, si
	std
	lodsw

	mov ax, 4c00h
	int 21h
code ends
end start