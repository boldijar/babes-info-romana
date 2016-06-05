; 15. Sa se citeasca de la tastatura doua nume de directoare dir1 si dir2. Sa
; se creeze directorul dir1\dir2. 

assume cs:code,ds:data

data segment
mesaj1 db 10,13,'Dati numele primului director: $',10,13
mesaj2 db 10,13,'Dati numele celui de-al doilea director: $',10,13
dir1 db 30 dup(?)
dir2 db 30 dup(?)
pnf db 10,13,'Path not found.$',10,13
acd db 10,13,'Acces denied, or pathname already exists.$',10,13
gata db 10,13,'S-a creat directorul.$',10,13
data ends

code segment
start:
mov ax,data
mov ds,ax

;citim primul director
mov ah,09h
mov dx,offset mesaj1
int 21h

mov si,0
mov ah,01h
int 21h
bucla1:
mov dir1[si],al
inc si
int 21h
cmp al,13
je sf1
mov dir1[si],al
jmp bucla1
sf1:
mov dir1[si],0

;citim numele celui de-al doilea fisier
mov ah,09h
mov dx,offset mesaj2
int 21h

mov si,0
mov ah,01h
int 21h
bucla2:
mov dir2[si],al
inc si
int 21h
cmp al,13
je sf2
mov dir2[si],al
jmp bucla2
sf2:
mov dir2[si],0

mov ah,3Bh ;schimb directorul curent in dir1
mov dx,offset dir1
int 21h
jc eroare

mov ah,39h ;creaza un subdirector
mov dx,offset dir2
int 21h
jc er
mov ah,09h
mov dx,offset gata
int 21h

eroare:
cmp ax,3
je pathnotfound
jmp sf

pathnotfound:
mov ah,09h
mov dx,offset pnf
int 21h
jmp sf

er:
cmp ax,3
je pathnotfound
cmp ax,5
je accesdenied

accesdenied:
mov ah,09h
mov dx,offset acd
int 21h

sf:
mov ax,4C00h
int 21h
code ends
end start
