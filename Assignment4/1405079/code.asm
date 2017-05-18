.model small
.stack 100h
.data
x1 dw ?
t0 dw ?
a2 dw ?
x3 dw ?
y3 dw ?
t1 dw ?

.code
PRINTLN PROC
@END_IF1:
XOR CX,CX
MOV BX,10D
@REPEAT1:
XOR DX,DX
DIV BX
PUSH DX
INC CX
OR AX,AX
JNE @REPEAT1
MOV AH,2
@PRINT_LOOP:
POP DX
OR DL,30H
INT 21H
LOOP @PRINT_LOOP
MOV DL,0DH
INT 21H
MOV DL,0AH
INT 21H
RET
PRINTLN ENDP

f proc
push BP
mov BP,SP
push ax
push bx
push cx
push dx
mov ax,[BP+4]
mov a2,ax
mov ax, a2
	call PRINTLN
	mov t0,9
push t0
call f
mov ax, 
mov a2, ax
pop dx
pop cx
pop bx
pop ax
pop BP
Ret 2
f endp

main proc
mov ax,@data
mov ds,ax
mov es,ax
mov t1,10
mov ax, t1
mov x3, ax
push x3
call f
mov ax, a2
mov y3, ax
mov ax, y3
	call PRINTLN
	mov ah,4ch
int 21h
main endp
end main

