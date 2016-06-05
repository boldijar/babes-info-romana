;x=yy-(d+m)+(h+yy)

assume cs:code, ds:data
data segment
	m db 2
	h db 165
	yy db 94
	d db 17
	x dw ?
data ends

code segment
start : mov ax, data
		mov ds, ax
		mov al, d
		add al, m  ; al:=d+m= 19
		mov bl, yy
		sub bl, al ; bl:= bl-al =94-19= 75
		mov al, h
		mov ah, 0  ; ax=h
		mov cl, yy
		mov ch, 0  ; cx=h 
		add ax, cx ; ax:= h+yy= 165+94= 259
		mov bh, 0
		add ax, bx ; bx := 75 + 259 = 334
		mov x, ax
		mov ax, 4c00h
		int 21h
code ends
end start