;(129+h)-(d+m)
assume cs:code, ds:data

data segment
	yy db 93
	h db 170
	d db 12
	m db 12
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	mov al, 129
        mov ah, 0
        mov bx, ax
        mov al, h
        mov ah, 0
	add ax, bx
        mov bx, ax
        mov al, d
        mov ah, 0
        mov cx, ax
        mov al, m
        mov ah, 0
        add ax, cx
        sub bx, ax

	mov dx,4c00h
	int 21h
code ends
end start