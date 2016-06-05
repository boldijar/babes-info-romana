assume cs:code,ds:data
data segment public
nr dw ?
c db ?
data ends

code segment public
public lit,cif


cif:
push bx
mov nr,bx
mov al,byte ptr nr
mov dl,16
mul dl
mov nr,ax
mov c,cl
mov al,c
sub al,'0'
mov ah,0
add nr,ax
mov bx,nr
pop bx
ret

lit:
mov nr,bx
mov al,byte ptr nr
mov dl,16
mul dl
mov nr,ax
mov c,cl
mov al,c
sub al,'A'
add al,10
mov ah,0
add nr,ax
mov bx,nr
ret

code ends
end