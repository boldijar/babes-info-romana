;Laborator 3 - probleme propuse

;Scrieti un program in limbaj de asamblare care sa rezolve una dintre urmatoarele expresii ;aritmetice, considerand urmatoarele domenii de definitie ale variabilelor: 
;13. (h+128)-(y+m+d)

assume cs:code, ds:data
data segment

m db 4
h dw 130
yy dw 100
d db 1

data ends
code segment
start:
	mov ax, data 
	mov ds, ax

	mov bx,h    ; bx = h
	add bx,128  ; bx = h + 128

	mov ah,0
	mov al,d    ; al = d
	add al,m    ; al = d + m
	cbw
	add ax,yy   ; ax = d + m + yy
	
	sub bx,ax   ; bx = bx - ax

	mov ax, 4C00h
	int 21h
code ends
end start
