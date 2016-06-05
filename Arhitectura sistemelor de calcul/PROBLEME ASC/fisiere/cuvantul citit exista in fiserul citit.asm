; 14. Sa se citeasca de la tastatura un cuvant si un nume de fisier. Sa se
; afiseze daca cuvantul exista sau nu in fisierul dat.

assume cs:code,ds:data

data segment
numefis db 12 dup(?)
cuvant db 20 dup(?)
lungfismax db 12
lungcuvmax db 20
lungfis db ?
lungcuv db ?
mcuvant db 'Dati cuvantul=',13,10,'$' 
mfisier db 'Dati numele fisierului=',13,10,'$' 
gasit db 'Cuvantul a fost gasit=',13,10,'$'
nugasit db 'Cuvantul nu a fost gasit=',13,10,'$'
mesaj1 db 'Fisierul nu a fost gasit ',13,10,'$'
mesaj2 db 'Nu s-a gasit calea ',13,10,'$'
mesaj3 db 'Acces interzis ',13,10,'$' 
buffer db 50 dup (?) 
data ends
code segment
start:
mov ax,data
mov ds,ax

mov ah,09h
mov dx,offset mfisier
int 21h
mov ah,0ah 
mov dx,offset lungfismax
int 21h

mov ah,09h
mov dx,offset mcuvant
int 21h
mov ah,0ah
mov dx,offset lungcuvmax
int 21h

mov al,lungfis
mov ah,0
mov si,ax
mov numefis[si],0 

mov al,lungcuv
mov ah,0
mov si,ax
mov cuvant[si],0 

mov ah,3dh ;am deschis fisier pt citire 
mov al,0
mov dx,offset numefis
int 21h
jc erori
;formez bufferul cu continutul fisierului 
mov ah,3fh
mov cx,50
mov dx,offset buffer
jc errbuf
mov bx,ax
int 21h
;verific daca cuvantul e in buffer
mov si,0
mov di,0
mov cl,lungfis 
bucla:
mov ah,cuvant[si]
cmp ah,buffer[di]
je bucla_egal
inc di 
cmp cl,di
je nueste
jmp bucla
bucla_egal:
inc si
inc di
cmp si,lungcuv
je este
jmp bucla
nueste:
mov ah,09h
mov dx,offset nugasit
int 21h
jmp sfarsit
este:
mov ah,09h
mov dx,offset gasit
int 21h
jmp sfarsit 

erori:
jmp sfarsit
errbuf:
jmp sfarsit 


sfarsit:
mov ax,4c00h
int 21h 


code ends 
end start 


