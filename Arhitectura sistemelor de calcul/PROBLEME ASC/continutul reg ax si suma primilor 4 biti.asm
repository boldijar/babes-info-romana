;1.Sa se tipareasca continutul registrilor si suma primilor 4 biti ai lor.

assume ds:data,cs:code
data segment
max db 'Continutul registrului ax este=$'
sax db 'Suma primilor 4 biti ai registrului ax este=$'
creg db 18 dup(?)
sreg db ?
data ends

code segment
start:
mov ax,data
mov ds,ax
mov ax,1001000111111111b

mov si,-1
mov cx,16
mov sreg,0

bucla:
shl ax,1
inc si
jc unu
mov creg[si],'0'
jmp cont

unu:
mov creg[si],'1'
cmp si,11
jbe cont 
add sreg,1

cont:
loop bucla

inc si
mov creg[si],10 ;pun in sir caract.10(Enter)ca sa treaca pe linia urm
inc si
mov creg[si],'$' ;pun $. Indica sfarsitul sirului de tiparit
mov dx,offset max ;incarc in dx mesaju
mov ah,09h ;incarc functia 09h, care tipareste un string
int 21h ;tiparesc mesajul

mov dx,offset creg ;incarc in dx continutul lui ax
mov ah,09h
int 21h ;il tiparesc

mov dx, offset sax ;incarc mesajul urmator (ala cu suma celor...)
mov ah,09h
int 21h ;il tiparesc

mov si,0
mov ah,sreg ;pun in ah suma celor patru biti
add ah,48 ;ii adun 48.Rezulta suma celor patru biti ca si caracter
;ah=4; ah+48=52; 52 este caracterul 4
mov creg[si],ah
inc si
mov creg[si],10 ;pun si enter la sfarsitul liniei
inc si
mov creg[si],'$' ;si caracterul ala
mov dx,offset creg
mov ah,09h
int 21h




mov ax,4C00h
int 21h

code ends
end start
