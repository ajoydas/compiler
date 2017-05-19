.model small
.stack 100h
.data
t0 dw ?
d2 dw ?
t1 dw ?
b2 dw ?, ?, ?, ?
t2 dw ?
t3 dw ?
a2 dw ?
t4 dw ?
t5 dw ?
t6 dw ?
t7 dw ?
.code
PRINTLN PROC
END_IF1:
XOR CX,CX
MOV BX,10D
REPEAT1:
XOR DX,DX
DIV BX
PUSH DX
INC CX
OR AX,AX
JNE REPEAT1
MOV AH,2
PRINT_LOOP:
POP DX
OR DL,30H
INT 21H
LOOP PRINT_LOOP
MOV DL,0DH
INT 21H
MOV DL,0AH
INT 21H
RET
PRINTLN ENDP
main proc
mov ax,@data
mov ds,ax
mov es,ax
mov t1,10
mov ax,t1
mov d2,ax
mov t3,4
mov t2,2
mov bx,t2
add bx,bx
mov ax,t3
mov b2[bx],ax
mov t4,2
mov bx,t4
add bx,bx
mov ax,b2[bx]
mov t5,ax
mov ax,d2
mov bx,t5
mov dx,0
div bx
mov t6,ax
mov a2,ax
call PRINTLN
mov t7,0
mov ax,t7
mov t0,ax
mov ah,4ch
int 21h
main endp
end main
