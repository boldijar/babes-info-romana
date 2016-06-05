; 9.Se da un sir de octeti S. Sa se construiasca un sir D1 care sa contina toate numerele pozitive si un sir D2 care sa contina toate numerele negative din S.
;Exemplu:
;  S: 1, 3, -2, -5, 3, -8, 5, 2
;  D1: 1, 3, 3, 5, 2
;  D2: -2, -5, -8

assume cs:code, ds:data
data segment
  s db 1,3,-2,-5,3,-8,5,2
  l equ $-s
  d1 db l dup(?)
  d2 db l dup(?)
data ends

code segment
start:
   mov ax, data  
   mov ds, ax

   mov si, 0
   mov di,0
   mov bx,0 
 
repeta:   
 
    pozitive:
      cmp s[si],0
      jb negative        
      mov al,s[si]
      mov d1[bx],al
      inc bx
      inc si
      
      cmp si,l
      jb repeta 
      jmp final
    negative:
      mov al, s[si]
      mov d2[di], al 
      inc si
      inc di
      
      cmp si, l
      jb repeta
     
    
final:
   mov ax,4c00h
   int 21h

code ends
end start