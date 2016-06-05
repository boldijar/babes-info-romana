assume cs:code,ds:data
data segment public
s1 db 'casamare'
l1 EQU $-s1 
s2 db 'care'
l2 EQU $-s1
s3 db 'casamea'
l3 EQU $-s1
d  db  l2+1 dup(?),'$' 
public s1,s2,s3,d,l1,l2,l3
data ends
code segment public
start:
      push data
      pop ds
	  jmp peste
	  
	  afisare proc
	  public afisare
	  mov ah,09h
	  mov dx, offset d
	  int 21h
	  ret
	  afisare endp
	  peste:
	  mov si,offset s1
      mov bx,offset s2
      mov di,offset d
	  mov dx,l1
	  mov bp,l2
      extrn prefix:proc
	  call prefix
	  mov si,offset s1
      mov bx,offset s3
	  mov dx,l1
	  mov bp,l2
	  call prefix
	  mov si,offset s2
      mov bx,offset s3
	  mov dx,l2
	  mov bp,l3
	  call prefix
	  call afisare
	  mov ax,4C00h
	  int 21h
code ends
end start	  