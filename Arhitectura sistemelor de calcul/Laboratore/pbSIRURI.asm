; 8.Dându-se un octet mod si doua siruri s1 si s2 (având aceeasi lungime n), sa se construiasca sirul s3 în felul urmator:
;- daca mod apartine [00h,0Fh] atunci s3[i]:=s1[i]+s2[i] (i=1,n)
;- daca mod apartine [10h,1fh] atunci s3[i]:=abs(s1[i]-s2[i])
;- daca mod apartine [20h,2fh] atunci s3:=s1+s2 (+ reprezinta concatenarea)
;- daca mod apartine [30h,3fh] atunci s3[i]:=s1[i]+s2[n-i] 
;- daca mod apartine [40h,4Fh] atunci s3:=~s1+~s2 (unde ~ reprezinta sirul parcurs în ordine inversa)
;- altfel s3:=s1. 


assume cs:code, ds:data
data segment

	SIR1 	DB 1,2,3,4
	LGSIR1	equ $-SIR1
	SIR2    DB 5,6,7,8
	LGSIR2	equ $-SIR2
	SIR3	Dw LGSIR1 DUP(?)
	MED		DB 0Fh
	
data ends

code segment
start:
  	mov ax, data
  	mov ds, ax
	
	MOV CH,0
	MOV CL,LGSIR1 ;în CX (contor) lungimea sirului
	MOV SI,0	; initializarea indexului
	CMP MED,0Fh 
	JG I1
	NEXT1:
	MOV AL,SIR1[SI]
	ADD AL,SIR2[SI]	; adunarea elementului curent
	MOV SIR3[SI],AX
	INC SI ; trecerea la elementul urmator în sir
	LOOP NEXT1	;decrement CX si salt la urmatorul 
				; element daca CX diferit de 0
    JMP EXIT
	I1:
	CMP MED,1fh
	JG I2
	NEXT2:
	MOV AL,SIR1[SI]
	SUB AL,SIR2[SI]	; scaderea elementului curent
	CMP AL,0
	JL ETICHETA
	JMP ETICHETA1
	ETICHETA:
	MOV AL,0
	MOV AL,SIR2[SI]
	SUB AL,SIR1[SI]
	ETICHETA1:
	
	MOV SIR3[SI],AX
	INC SI ; trecerea la elementul urmator în sir
	LOOP NEXT2	;decrement CX si salt la urmatorul 
				; element daca CX diferit de 0
	JMP EXIT
	I2:
	CMP MED,2fh
	JG I3
	NEXT3:
	MOV AH,SIR1[SI]
	MOV AL,SIR2[SI]	; concatenarea elementelor sirurilor
	MOV SIR3[SI],AX
	INC SI ; trecerea la elementul urmator în sir
	LOOP NEXT3	;decrement CX si salt la urmatorul 
				; element daca CX diferit de 0
    JMP EXIT
	I3:
	CMP MED,3fh
	JG I4
	NEXT4:
	MOV AL,SIR1[SI]
	MOV DH,0
	MOV DL,LGSIR1
	SUB DX,SI
	MOV SI,DX
	SUB AL,SIR2[SI]	; concatenarea elementelor sirurilor
	MOV SIR3[SI],AX
	INC SI ; trecerea la elementul urmator în sir
	LOOP NEXT4	;decrement CX si salt la urmatorul 
				; element daca CX diferit de 0
    JMP EXIT
	I4:
	CMP MED,4Fh
	JG I5
	NEXT5:
	MOV DH,0
	MOV DL,LGSIR1
	SUB DX,SI
	MOV SI,DX
	MOV AL,SIR1[SI]
	SUB AL,SIR2[SI]	; concatenarea elementelor sirurilor
	MOV SIR3[SI],AX
	INC SI ; trecerea la elementul urmator în sir
	LOOP NEXT5	;decrement CX si salt la urmatorul 
				; element daca CX diferit de 0
    JMP EXIT
	I5:
	NEXT6:
	MOV AL,SIR1[SI]
	MOV SIR3[SI],AX
	INC SI
	LOOP NEXT6
	
EXIT:	
	mov ax, 4c00h ; terminam programul
  	int 21h
code ends
end start