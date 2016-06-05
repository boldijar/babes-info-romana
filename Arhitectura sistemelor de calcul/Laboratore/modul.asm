assume cs:code, ds:data
data segment public
	extrn s1:byte,s2:byte,s3:byte,l1:abs,l2:abs,l3:abs
data ends

code segment public	
	FormareSuf proc
	public FormareSuf
	mov cx,0
	repeta:
		mov dl,[si]
		mov bl,[di]
		cmp dl,bl
		jne afis
		push dx
		dec si
		dec di
		inc cx
	jmp repeta
	afis:
		pop dx
		mov ah,02h   ;iau cate un caracter de pe stiva si o tiparesc
		int 21h
		dec cx
	    cmp cx,0
	jne afis

	
ret
FormareSuf endp
code ends
end
	
		
	
	
		
	
	
