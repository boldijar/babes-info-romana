; Se dau 2 siruri de cuvinte. Sa se concateneze sirul octetilor inferiori din cuvintele [rimului sir cu sirul octetilor superiori din cuvintele celui de-al doilea sir.
; Sirul obtinut trebuie ordonat crescator in interpretarea cu semn.

assume cs:code,ds:data
data segment
	s	dw	2345h,0A5h,368h,3990h
	len_s	equ ($-s)/2
	t	dw	4h,2655h,10
	lent_t	equ ($-t)/2
	len_u	equ	len_s+len_t
	u	db	len_u dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	lea si,s ;mov si,offset s
	lea di,u
	cld
	mov cx,len_s
	jcxz final
	
	repeta:
		lodsw ; ds:si -> ax, si=si+2
		stosb ; al -> es:di , di=di+1
	loop repeta
	
	lea si,t
	mov cx,len_t
	jcxz final
	
	repeta1:
		lodsw 
		xchg al,ah
		stosb
	loop repeta1
	
	mov dx,1 ; <=> ok=true
	repeta2:
		cmp dx,0
		je final
		lea si,u
		mov dx,0
		mov cx, len_u-1
		repeta3:
			mov al,byte ptr ds:[si]
			cmp al,byte ptr ds:[si+1]
			
			jle iteratie_noua ;comparatie cu semn
			
			mov ah,byte ptr ds:[si+1]
			mov byte ptr ds:[si],ah
			mov byte ptr ds:[si+1],al
			
			mov dx,1
			
			iteratie_noua:
				inc si
		loop repeta3
	jmp repeta2
	
	final:
		mov ax,4c00h
		int 21h
code ends
end start