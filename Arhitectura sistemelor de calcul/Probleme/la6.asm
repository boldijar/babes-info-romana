; Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte diferenta dintre fiecare 2 elemente consecutive din S.
; Exemplu:
; S: 1, 2, 4, 6, 10, 20, 25
; D: 1, 2, 2, 4, 10, 5

assume cs:code, ds:data
data segment
	s db 1,2,4,6,10,20,25
	l equ $-s
	d db [s[0]]
	c db [s[1]]
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov si,0
	repeta :
		mov al,byte ptr s[si]
		mov bl,byte ptr s[si+1]

		sub bl,al
		mov d[si],bl
		inc si
		cmp si,l-1
	jne repeta
	mov ax,4c00h
	int 21h
code ends
end start