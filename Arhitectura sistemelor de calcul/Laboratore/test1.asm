assume cs:code,ds:data
data segment
	sir	dd 	12345678h,68A3456Bh
	l	equ	$-sir
	msg	db	'Numarul este: $'
data ends
code segment
start:
push data
pop ds

lea si,sir
mov dl,0
mov cx,l
repeta:
	mov al,byte ptr ds:[si]
	cmp al,0
	jl numara
	inc si
	jmp next
	numara:
		inc dl
		inc si
	next:
		loop repeta
mov al,dl
mov dx,offset msg
mov ah,09h
int 21h
mov dl,al
add dl,'0'
mov ah,02h
int 21h
	
	
mov ax, 4c00h
int 21h
code ends
end start