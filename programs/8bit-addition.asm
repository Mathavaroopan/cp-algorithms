cr equ 0dh
lf equ 0ah
data segment
 table db '0123456789abcdef'
 decilength dw 4
 decimal db '0255'
 hexadecimal dw 0
 multfactor dw 1
 message db ' the hexadecimal number is:'
 hexascii db 4 dup(' ')
 db cr, lf, '$'
data ends
code segment
 assume cs:code, ds:data
 start:
 mov ax, data
 mov ds, ax
 mov cx, decilength
 lea si, decimal
 add si,3
 top:
 mov al, [si]
 and ax, 0000fh
 mul multfactor
 add hexadecimal, ax
 mov ax, multfactor
 mov bx, 0000ah
 mul bx
 mov multfactor, ax
 dec si
 loop top
 lea si, hexascii
 add si,3
 lea bx, table
 mov ax, hexadecimal
 and ax,0000fh
 xlat
 mov [si], al
 dec si
 mov ax, hexadecimal
 and ax,000fh
 mov cl, 04h
 shr al,cl
 xlat
 mov [si], al
 dec si
 mov ax, hexadecimal
 and ax,00fh
 mov cl, 08h
 shr ax,cl
 xlat
 mov [si], al
 dec si
 mov ax, hexadecimal
 and ax,0fh
 mov cl, 00ch
 shr ax,cl
 xlat
 mov [si], al
 dec si
 mov ah,09h
 lea dx, message
 int 21h
 quit:
 mov al,0
 mov ah,04ch
 int 21h
code ends
end start
