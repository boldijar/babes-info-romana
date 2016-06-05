; Laborator 5
;3. Se dau cuvintele A si B. Sa se obtina cuvantul C:
;- bitii 0-2 ai lui C coincid cu bitii 12-14 ai lui A
;- bitii 3-8 ai lui C coincid cu bitii 0-5 ai lui B
;- bitii 9-15 ai lui C coincid cu bitii 3-9 ai lui A

assume cs:code, ds:data
data segment
	A dw 1011011000111101b
	B dw 0100111101001011b
	C dw 0000000000000000b ; C = 1000111001011011b
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	mov bx, 0
	mov ax, 0
	mov ax, A
	shl ax,1; ax = 0110110001111010b
	shr ax, 13 ; ax = 0000000000000011b
	add bx,ax ; bx = 0000000000000011b
	
	mov ax, B
	and ax, 0000000000111111b; ax = 0000000000001011b
	shl ax, 3; ax = 0000000001011000b
	add bx,ax
	
	mov ax, A
	and ax, 0000001111111000b
	shl ax, 6
	add bx, ax
	
	mov ax, 4c00h
	int 21h
	
code ends
end start