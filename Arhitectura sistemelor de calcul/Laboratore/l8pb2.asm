;2. Sa se citeasca cite un caracter de la tastatura, fara ecou. Daca
; este cifra, sa se tipareasca pe ecran, daca este caracterul
; '$', se termina programul, in orice alta situatie se adauga
; caracterul intr-un buffer care se va tipari in final pe ecran.

assume cs:code, ds:data

data segment
buffer db 20 dup(?)
data ends

code segment
start:
mov ax,data
mov ds,ax

mov si,0
mov ah,08h                                                          ;console char input without echo - adica citeste un caracter cand apelez intreruperea...
int 21h                                                             ;citesc caracter pe care il pune in al

bucla: 
cmp al,'$' 
je sfbucla                                                         ;daca e '$' am terminat
cmp al,'0'                                                         ;DACA E MAI MARE DECAT 0 (VERIFIC DACA E NUMAR)
jb et 
cmp al,'9'                                                         ;daca e mai mic decat 9 am numar
ja et

mov dl,al                                                          ;cand ajung aici am numar, pregatesc tiparirea
mov ah,02h                                                         ;pun in ah 02h adica character output 
int 21h                                                            ;tiparesc caracterul din dl
jmp et1                                                            ;ma duc la et1 (citirea urm caracter)

et: 
mov buffer[si],al                                                  ;daca ajung aici am alt caracter
add si,1                                                           ;il adaug in buffer si cresc adresa curenta din buffer

et1:
mov ah,08h                                                         ;pregatesc citirea
int 21h ;citesc un caracter
jmp bucla                                                          ;repet procedeul

sfbucla:
mov buffer[si],al                                                  ;mut in buffer ultimul caracter ($)
mov ah,09h                                                         ;09h - print string pregateste tiparirea
mov dx,offset buffer                                               ;dx offsetul bufferului
int 21h                                                            ;tiparesc bufferul

mov ax,4C00h                                                       ;iesire din program...
int 21h

code ends
end start
