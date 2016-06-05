;Problema II gr. : 212-213. Am facut afisari in bazele 2,10,16

assume cs:code, ds:data
data segment
        a dw 2150
        b db 6
        tab db "0123456789ABCDEF"
        zece dw 10
        saispe dw 16
        doi dw 2
        cat dw ?
        re dw ?
data ends
 
code segment
start:
        mov ax, data
        mov ds, ax
       
        afis_10 macro a
                local  do
                local doo
                mov ax, a
                mov dx, 0
                mov cx, 0
                do:
                        div zece
                        push dx
                        mov dx, 0
                        inc cx
                        cmp ax, 0
                jne do
               
                doo:
                        pop ax
                        add al, "0"
                        mov dl, al
                        mov ax, 0200h
                        int 21h
                loop doo
        endm
       
        new_line macro
                mov dl, 10
                mov ax, 0200h
                int 21h
                mov dl, 13
                mov ax, 0200h
                int 21h
        endm
       
        afis_16 macro a
                local  do
                local doo
                mov ax, a
                mov dx, 0
                mov cx, 0
                do:
                        div saispe
                        push dx
                        mov dx, 0
                        inc cx
                        cmp ax, 0
                jne do
               
                doo:
                        pop ax
                        lea bx, tab
                        xlat tab
                        mov dl, al
                        mov ax, 0200h
                        int 21h
                loop doo
        endm
       
        afis_2 macro a
                local  do
                local doo
                mov ax, a
                mov dx, 0
                mov cx, 0
                do:
                        div doi
                        mov dh, 0
                        push dx
                        mov dx, 0
                        inc cx
                        cmp ax, 0
                jne do
               
                doo:
                        pop ax
                        add al, "0"
                        mov dl, al
                        mov ax, 0200h
                        int 21h
                loop doo
        endm
               
       
        mov ax, a
        mov bl, b
        mov bh, 0
        div bx
        mov re, dx
        mov cat, ax
       
        afis_10 cat    
        new_line
        afis_10 re
        new_line
        new_line
        afis_16 cat
        new_line
        afis_16 re
        new_line
        new_line
        afis_2 cat
        new_line
        afis_2 re
       
       
        mov ax, 4c00h
        int 21h
code ends
end start