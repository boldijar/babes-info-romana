; 11. Se da un sir de dublucuvinte. Sa se obtina sirul format din octetii
; superiori ai cuvintelor inferioare din elementele sirului de dublucuvinte,
; care sunt multiplii de 10. 
; Ex: Se da sirul de dublucuvinte: s dd 12345678h, 1A2B3C4Dh, FE98DC76h 
;  Sa se obtina sirul d db 56h, 3Ch, DCh.


ASSUME cs:code, ds:data
data segment
	sir dd 12345678h, 1A2B3C4Dh, 0FE98DC76h 
	len EQU ($-sir)/4 ;lungimea sirului de dublucuvinte
	
	d db len dup(?)
	zece db 10
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	cld ; direction flag primeste valoarea 0, parcurgere de la stanga la dreapta
	mov si, offset sir ; in si punem adresa sirului si
	mov di, 0 ; contor pentru sirul d
	
	mov cx, len
	repeta:
		lodsw ; in ax avem cuvantul mai putin semnificativ de la adresa ds:si
		mov al, ah; in al punem octetul mai superior din cuvant
		mov bl, al; facem o copie a lui al
		mov ah, 0 ; avem nevoie doar de al
		div zece ; il impartim la 10 pentru a vedea daca este multiplu de 10
		cmp ah,0 ; comparam restul cu 0
		jnz nuezero ; daca restul nu este zero sarim la eticheta nuezero
		jz ezero ; daca restul este 0 sarim la eticheta ezero
		nuezero:
			inc si
			inc si
			loop repeta
		ezero:
			mov d[di], bl
			inc di
			inc si
			inc si
			loop repeta
	
	mov ax, 4c00h
	int 21h
code ends
end start