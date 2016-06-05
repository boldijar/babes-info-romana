;5. Se dau cuvintele A si B. Sa se obtina cuvântul C:
;
;- bitii 0-3 ai lui C coincid cu bitii 8-11 ai lui A
;- bitii 4-10 ai lui C au valoarea 0
;- bitii 11-15 ai lui C coincid cu bitii 11-15 ai lui B

assume cs:code, ds:data
data segment
  a dw 1100011011100001b
  b dw 1111000111110101b
  c dw ?
data ends

code segment
start:
  mov ax, data ; incarcam adresa segmentului de date in resgistrul ds
  mov ds, ax

  mov bx,0 ; in bx vom calcula rezultatul
  mov ax,a ; izolam bitii 8-11 ai lui a
  and ax, 0000111100000000b ; 
  mov cl, 7
  ror ax, cl ; rotim 7 pozitii spre dreapta
  or bx, ax ; punem bitii in rezultat

  and bx, 1111100000001111b ; facem biti 4-10 din rezultat sa aiba valoarea 0


  mov ax, b ; izolam biti 11-15 ai lui b
  and ax, 1111100000000000b
  or bx, ax ; punem bitii in rezultat

  mov c, bx ; punem valoarea din registru in variabila rezultat

  mov ax, 4c00h ; terminam programul
  int 21h
code ends
end start
