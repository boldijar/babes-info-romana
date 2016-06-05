assume cs:code, ds:data
data segment public           ;indica editorului de legaturi sa concateneze acest segment cu alte eventuale segmente cu acelasi nume, obtinandu-se un unic segment 
	s1 db 'abcde'
	l1 equ $-s1
	s2 db 'tetbcde'
	l2 equ $-s2
	s3 db 'ertbcde'
	l3 equ $-s3
	mesaj1 db 'Cel mai lung sufix comun pentru primele 2 siruri este: ','$'
	mesaj2 db 'Cel mai lung sufix pentru primul si ultimul sir este: ','$'
	mesaj3 db 'Cel mai lung sufix pentru ultimele 2 siruri este: ','$'
	
public s1,s2,s3,l1,l2,l3  ; utilizata pt a exporta simbolurile definite in alte module 
data ends
code segment public
	start:
		mov ax, data
		mov ds, ax
		mov es, ax
		
			mov si, offset s1
			add si,l1
			sub si,1
			mov di, offset s2
			add di,l2
			sub di,1
			mov ah,09h
			mov dx, offset mesaj1
			int 21h			
			extrn FormareSuf:proc  ;folosita pt a face vizibile in modulul curent simbolurile definite in alte module
			call FormareSuf		
			mov ah,02h
			mov dl,13
			int 21h
			mov ah,02h
			mov dl,10
			int 21h
			
			mov si, offset s1
			add si,l1
			sub si,1
			mov di, offset s3
			add di,l3
			sub di,1
			mov ah,09h
			mov dx, offset mesaj2
			int 21h	
			call FormareSuf	
			mov ah,02h
			mov dl,13
			int 21h
			mov ah,02h
			mov dl,10	
			int 21h
			
			mov si, offset s2
			add si,l2
			sub si,1
			mov di, offset s3
			add di,l3
			sub di,1
			mov ah,09h
			mov dx, offset mesaj3
			int 21h	
			call FormareSuf
			
			mov ax, 4c00h
			int 21h
			
code ends
end start
		
		

