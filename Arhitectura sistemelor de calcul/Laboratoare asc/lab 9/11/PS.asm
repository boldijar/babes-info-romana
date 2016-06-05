assume cs:code, ds:data
data segment

data ends

code segment public
public compara

compara:
	;input: SI- offset-ul sirului sursa
	;		DI- offset-ul sirului de comparat
	;		CX- cate pozitii comparam(lunginea primului cuvant)

	push si
	cld
	loop2:
		cmp byte ptr [si],32
		je et1
		cmpsb
		jne et2
	loop loop2
	cmp cx,0
	je et3
	
	et3:
		; sirurile de comparat sunt egale
		mov al,2
		jmp final2
	
	et2:
		;sirurile de comparat nu sunt egale
		mov al,0
		jmp final2
	
	et1:
		; am intalnit un spatiu
		mov al,1
		pop bx
		jmp done
	final2:
	pop si
done:
ret

code ends
end