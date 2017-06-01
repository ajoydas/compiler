.model small
.stack 100h
.data
t0 dw ?
a2 dw ?
b2 dw ?
i2 dw ?
t1 dw ?
t2 dw ?
t3 dw ?
t4 dw ?
t5 dw ?

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
mov t1,0
mov ax,t1
mov b2,ax
mov t2,0
mov ax,t2
mov i2,ax
L4:
mov t3,4
mov ax,i2
cmp ax,t3
jl L0
mov t4,0
jmp L1
L0:
mov t4,1
L1:
cmp t4, 0
je L5
mov t5,3
mov ax,t5
mov a2,ax
L2:
DEC a2
cmp a2,0
je L3
INC b2
jmp L2
L3:

INC i2
jmp L4
L5:

mov ax,a2
call PRINTLN
mov ax,b2
call PRINTLN
mov ax,i2
call PRINTLN
mov ah,4ch
int 21h
main endp

end main

