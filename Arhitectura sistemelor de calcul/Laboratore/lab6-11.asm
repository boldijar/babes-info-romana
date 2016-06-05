assume cs:code,ds:data
data segment
	s1 db '+','4','2','a','8','4','X','5'
	l equ $-s1
	s2 db 'a','4','5'
	k equ $-s1
	d db l dup (?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov si, offset s1
	mov bx,offset d
	repeta:
		mov di,offset s2		
		mov al,byte ptr[si]
		for1:
			mov cl,byte ptr[di]
			cmp al,cl
			jne for
			jmp mareste	
				for:
					
					cmp di, k
					jg muta
					jmp creste
					muta:
						mov d[bx],al
						inc bx
						jmp mareste
					creste:
						inc di
						jmp for1
				
		mareste:
	inc si	
	cmp si,l
	jne repeta
	mov ax,4c00h
	int 21h
code ends 
end start	
		
		
			
			
			