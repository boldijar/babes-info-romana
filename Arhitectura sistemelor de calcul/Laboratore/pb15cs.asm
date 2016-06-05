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
        cbw
        mov bx, ax
        mov al, h
        cbw
	add ax, bx
        mov bx, ax
        mov al, d
        cbw
        mov cx, ax
        mov al, m
        cbw
        add ax, cx
        sub bx, ax

	mov dx,4c00h
	int 21h
code ends
end start