.model small
.stack 100h
.data
x1 dw ?
y1 dw ?
z1 dw ?
a1 dw ?
t0 dw ?
t1 dw ?
b2 dw ?
a2 dw ?
t2 dw ?
t3 dw ?
t4 dw ?
t5 dw ?
a4 dw ?, ?, ?
c4 dw ?
i4 dw ?
j4 dw ?
d4 dw ?
t6 dw ?
t7 dw ?
t8 dw ?
t9 dw ?
t10 dw ?
t11 dw ?
t12 dw ?
t13 dw ?
t14 dw ?
t15 dw ?
t16 dw ?
t17 dw ?
t18 dw ?
t19 dw ?
t20 dw ?
t21 dw ?
t22 dw ?
t23 dw ?
t24 dw ?
t25 dw ?
t26 dw ?
t27 dw ?
t28 dw ?
t29 dw ?
t30 dw ?
t31 dw ?
t32 dw ?
t33 dw ?
t34 dw ?
t35 dw ?
t36 dw ?
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
var proc
push BP
mov BP,SP
push ax
push bx
push cx
push dx
push b2
mov ax,[BP+4]
mov b2,ax
push a2
mov ax,[BP+6]
mov a2,ax
add ax,b2
mov t1,ax
mov t0,ax
pop a2
pop b2
pop dx
pop cx
pop bx
pop ax
pop BP
Ret 4
var endp
foo proc
push BP
mov BP,SP
push ax
push bx
push cx
push dx
mov t2,2
mov ax,t2
mov x1,ax
mov t3,5
mov ax,x1
sub ax,t3
mov t4,ax
mov y1,ax
pop dx
pop cx
pop bx
pop ax
pop BP
Ret 0
foo endp
main proc
mov ax,@data
mov ds,ax
mov es,ax
mov t7,1
mov t6,0
mov bx,t6
add bx,bx
mov ax,t7
mov a-1[bx],ax
mov t9,5
mov t8,1
mov bx,t8
add bx,bx
mov ax,t9
mov a-1[bx],ax
mov t10,0
mov bx,t10
add bx,bx
mov ax,a-1[bx]
mov t11,ax
mov t12,1
mov bx,t12
add bx,bx
mov ax,a-1[bx]
mov t13,ax
mov ax,t11
add ax,t13
mov t14,ax
mov i4,ax
call PRINTLN
mov t15,2
mov t16,3
mov ax,t15
mov bx,t16
mul bx
mov t17,ax
mov t18,5
mov t19,3
mov ax,t18
mov bx,t19
mov dx,0
div bx
mov t20,dx
mov t21,4
mov ax,t20
cmp ax,t21
jl L0
mov t22,0
jmp L1
L0:
mov t22,1
L1:
mov t23,8
mov ax,t22
mov bx,t23
cmp ax,0
je L2
cmp bx,0
je L2
L3:
mov t24,1
jmp L4
L2:
mov t24,0
L4:
mov ax,t17
add ax,t24
mov t25,ax
mov t26,2
mov ax,t25
mov bx,t26
cmp ax,0
jne L5
cmp bx,0
jne L5
L6:
mov t27,0
jmp L7
L5:
mov t27,1
L7:
mov ax,t27
mov j4,ax
call PRINTLN
mov t28,1
mov t29,2
mov t30,3
mov ax,t29
mov bx,t30
mul bx
mov t31,ax
push t28
push t31
call var
mov t32,3
mov t33,2
mov ax,t32
mov bx,t33
mul bx
mov t34,ax
mov ax,t0
add ax,t34
mov t35,ax
mov d4,ax
call PRINTLN
mov t36,0
mov ax,t36
mov t5,ax
mov ah,4ch
int 21h
main endp
end main
