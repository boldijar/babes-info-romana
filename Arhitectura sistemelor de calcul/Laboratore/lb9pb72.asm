assume cs:code,ds:data
data segment public 
data ends
code segment public
prefix proc
public prefix
repeta:mov cl,byte ptr [si]
       mov ch,byte ptr [bx]
	   cmp cl,ch; 
	   jne next
	   mov byte ptr [di],cl
	   inc di
	   inc si
	   inc bx
	   cmp si,dx
	   je next
	   cmp bx,bp
	   je next
	   jmp repeta
	   next: inc di
  
	ret
prefix endp
code ends
end	
                		
		
            			 
	        			
	   
