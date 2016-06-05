assume cs:code, ds:data
data segment
    	a dw 0111011101010111b
    	b dw 1001101110111110b
	c dw ?
data ends
code segment
start:
	mov ax,data ; incarcam adresa segmentului de date in registrul ds
	mov ds,ax
	
	mov bx,0 ; in registrul bx vom calcula rezultatul
	or bx, 0000000000111000b ;facem biti 3-5 din rezultat sa aiba valoarea 1
	mov ax, a ;izolam bitii 11-14 ai lui a
	and ax, 0111100000000000b
	mov cl,5
	ror ax,cl ;rotim 5 pozitii spre dreapta
	or bx,ax ;punem bitii in rezultat
	mov ax,b ;izolam bitii 1-6 ai lui b
	and ax, 0000000001111110b
	mov cl,9
	ror ax,cl ;rotim 5 pozitii spre dreapta
	or bx,ax
	mov c, bx ;; punem valoarea din registru in variabila rezultat

	mov ax, 4c00h ; terminam programul
     	int 21h
code ends
end start

	