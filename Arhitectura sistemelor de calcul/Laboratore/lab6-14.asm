;14
assume cs:code,ds:data
data segment
	s1 db 'a','b','c','1','2','3','+','*'
	l1 equ $-s1
	s2 db '9','8','f','g'
	l2 equ $-s2
	l3 equ l1/3+l2+1
	d db l3 dup(?)
data ends
code segment
	start:
		mov ax,data
		mov ds,ax
		
		mov si,0
		mov di,0
		repeta:
			mov al,byte ptr s1[si]
			mov byte ptr d[di],al
			inc di
			add si,3
			cmp si,l1
		jle repeta
		
		mov si,l2-1
		reia:
			mov al,byte ptr s2[si]
			mov byte ptr d[di],al
			inc di
			dec si
			cmp si,0
		jge reia
	
		mov ax,4c00h
		int 21h
code ends
end start
		
		
		
		
		
		
		
		
		
		