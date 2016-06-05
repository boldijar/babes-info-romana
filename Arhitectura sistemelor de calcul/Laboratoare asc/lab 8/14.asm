;14. Sa se citeasca de la tastatura un cuvant si un nume de fisier. 
;Sa se afiseze daca cuvantul exista sau nu in fisierul dat.

ASSUME cs:code,ds:data
data SEGMENT
   
   maxCuvName db 50
   lcuv db ?
   cuv db 50 dup(?)
   
   maxFileName db 50 
   lFileName db ?
   fileName db 50 dup(?)
   
   buffer db 100 dup(?)
  
   msg db 'Dati numele fisierului            $'
   readingerror db 'Eroare la citirea din fisier        $'
   openingerror db 'Eroare la deschiderea fisierului   $'
   msg2 db 'Dati numele cuvantului:$'
   not_found_it db 'Cuvantul nu a fost gasit in fisier!$'
   found_it db 'Cuvantul a fost gasit in fisier!$'
   
   emptyline db '                                                                                $'
   found db 0

data ENDS
code SEGMENT
start:
   mov ax,data
   mov ds,ax 
   
   ;Afisam un mesaj corespunzator pentru citirea fisierului
   mov ah,09h
   mov dx,offset msg
   int 21h
   
   ;Citim numele fisierului
   
   mov ah,0ah
   mov dx,offset maxFileName
   int 21h
   
    ;Transformam numele fisierului intr-un scris asciiz ce se termina cu byte-ul 0
    mov al, lFileName
	xor ah, ah
	mov si, ax
	mov fileName[si], 0
	
	;Citim din fisier toti octetii intr-un buffer
	
	mov ah, 3dh
	mov al, 0 ; deschidem fisierul pentru citire
	mov dx, offset fileName ;Specificam numele fisierului care il deschidem prin offsetul sau 
	int 21h
	jc OpenError ;Daca carry flag este setat, inseamna ca avem o eroare la deschiderea fisierului,
				 ; prin urmare sarim la eticheta OpenError
	
	mov bx,ax ;Salvam identificatorul fisierului in bx

	mov ah,3fh ;Comanda pentru citirea din fisier
	mov dx,offset buffer
	mov cx,100
	int 21h
	jc ReadError
	
	mov cx,ax ;Salvam numarul de octeti cititi in registrul cx
	
    mov ah,09h
	mov dx,offset emptyline
	int 21h
	
	;Afisam un mesaj corespunzator pentru citirea cuvantului:
	mov ah,09h
	mov dx,offset msg2
	int 21h
	
	mov ah,09h
	mov dx,offset emptyline
	int 21h
	
	;Citim de la tastatura numele cuvantului:
	mov ah,0ah
	mov dx,offset maxCuvName
	int 21h
	
	mov ah,09h
	mov dx,offset emptyline
	int 21h
	
	mov si,0
	mov bx,0
	
	Repeta:
			mov al,buffer[si]
			cmp al,cuv[bx]
			jne NotEqual
			
			add bx,1
			
			mov al,lcuv
			mov ah,0
			
			cmp bx,ax
			jne Here
			;Daca s-a ajuns aici, inseamna ca a fost gasit cuvantul
			mov found,1
			
			NotEqual:
					mov bx,0	
			Here:
				 inc si
			;Ciclam pana cand am gasit cuvantul sau pana cand am parcurs tot bufferul de octeti
			cmp found,1
			je Break
	loop Repeta
	mov ah,09h
	mov dx,offset not_found_it
	int 21h
	
	jmp EndPrg
	
	Break:
	mov ah,09h
	mov dx,offset found_it
	int 21h
	
	jmp EndPrg
	OpenError:
				mov ah,09h
				mov dx,offset openingerror
				int 21h
				jmp EndPrg
	
	ReadError:
				mov ah,09h
				mov dx,offset readingerror
				int 21h
	EndPrg:
	mov ax,4c00h
	int 21h
code ends
end start