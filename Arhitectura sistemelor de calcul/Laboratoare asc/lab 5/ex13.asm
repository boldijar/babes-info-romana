;Laborator 5 - probleme propuse
;13. Dandu-se 4 octeti, sa se obtina in AX suma numerelor intregi
;reprezentate de bitii 4-6 ai celor 4 octeti.

 assume cs: code , ds: data
 data segment
	a dw 01011100b
        b dw 11101100b
	c dw 11111111b
	d dw 00000000b
 
 data ends

 code segment 
 start:
	mov ax,data
	mov ds,ax

	mov ax, 0 ; in registrul bx vom calcula rezultatul	
	
	mov bx,a         ;punem in bx pe a
	and bx,01110000b ; izolam bitii 4-6 a lui a
	ror bx,4  	 ; rotim 4 pozitii spre dreapta
	or ax,bx   	 ; punem bitii  4-6 a lui a in ax

	mov bx,b         ; punem in bx pe b
	and bx,01110000b ; izolam bitii 4-6 a lui b
	ror bx,4  	 ; rotim 4 pozitii spre dreapta
	add ax,bx 	 ; adun bx-ul la ax,
      
	mov bx,c         ; punem in bx pe c
	and bx,01110000b ; izolam bitii 4-6 a lui c
	ror bx,4  	 ; rotim 4 pozitii spre dreapta
	add ax,bx 	 ; adun bx-ul la ax,
        
	mov bx,d         ; punem in ax pe d
	and bx,01110000b ; izolam bitii 4-6 a lui d
	ror bx,4  	 ; rotim 4 pozitii spre dreapta
	add ax,bx	 ; adun bx-ul la ax,
	

	mov ax,4c00h
	int 21h
code ends
end start