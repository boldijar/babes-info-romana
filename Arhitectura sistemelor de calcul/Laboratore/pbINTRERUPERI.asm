;2. Sa se citeasca câte un caracter de la tastatura, fara ecou. 
;Daca este cifra, sa se tipareasca pe ecran, daca este caracterul '$', 
;se termina programul, în orice alta situatie se adauga caracterul
;într-un buffer care se va tipari în final pe ecran.

assume cs:code, ds:data
data segment
data ends

code segment
start:
  	mov ax, data
  	mov ds, ax

main:
    mov ah,07h
    int 21h
    call verificare 
jmp main

verificare:    
    cmp al,'0'
    je print 
    
    cmp al,'1'
    je print
    
    cmp al,'2'
    je print 
    
    cmp al,'3'
    je print   
    
    cmp al,'4'
    je print   
    
    cmp al,'5'
    je print   
    
    cmp al,'6'
    je print   
    
    cmp al,'7'
    je print   
    
    cmp al,'8'
    je print   
    
    cmp al,'9'
    je print   
    
    cmp al,'$'
    je exit

jmp stocare
jmp main     

stocare:    
    mov [SI],ax
    inc SI
    inc cx    
jmp main

print_2: 
       sub SI,bx
       mov dl,[SI]
       mov ah,02h
       int 21h 
       mov bx,00h
       inc SI
loop print_2 

jmp exit_2

print:   
       mov dl,al
       mov ah,02h
       int 21h 
jmp main
            
exit:  
        mov bx,cx
	cmp cx,00h
	jne print_2
	je exit_2
 
exit_2:
	mov ax, 4c00h ; terminam programul
  	int 21h
code ends
end start