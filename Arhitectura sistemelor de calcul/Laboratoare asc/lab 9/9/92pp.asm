;9. Se cere sa se citeasca de la tastatura un sir de numere, date in baza 16.

assume cs:code,ds:data

data segment public
buffer db 100, 100 dup(?)
lmax db 100
l db ?
s dw 100 dup(?)
ls equ $-s
nr dw 0
c db ','
c1 dw ?
data ends

code segment public
extrn cif:proc
extrn lit:proc

start:
mov ax,data
mov ds,ax

mov ah,0ah
mov dx,offset buffer
int 21h

mov cl,buffer[1]
mov ch,0
mov si,2
mov di,0
mov nr,0

cn:
mov bx,10
cmp cx,0
jz rr
mov al,buffer[si]
cmp al,c
je rr
cmp al,'9'
jbe cif1 
mov ax,0
jmp lit1

cif1:
mov bx,nr
mov c1,cx
mov cl,buffer[si]
call cif
mov cx,c1
mov nr,bx
inc si
loop cn

lit1:
mov bx,nr
mov c1,cx
mov cl,buffer[si]
call lit
mov cx,c1
mov nr,bx
inc si
loop cn


rr:
mov ax,nr
mov s[di],ax
inc di
inc di
mov nr,0
inc si
cmp cx,0
jz sf
loop cn

sf:
mov ax,4c00h
int 21h
code ends 
end start