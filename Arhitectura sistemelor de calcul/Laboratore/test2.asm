assume cs:code,ds:data
data segment
a  db  3
b  dd  256
c  dw 256

data ends
code segment
start:
	push data
	pop ds
	
	lea  bx,[di+(5 or 6)]

mov ax,4c00h
int 21h
code ends
end start