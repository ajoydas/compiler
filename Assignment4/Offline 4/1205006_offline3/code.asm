.model small
.stack 100h
.data
a dw  ?
b dw ?
c dw ?
i dw ?
t0 dw ?
t1 dw ?
t2 dw ?

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
RET
PRINTLN ENDP

main proc
	mov ax,@data
	mov ds,ax
	mov es,axmov ax, 10
	mov a, ax
	mov ax, 20
	mov b, ax
	mov ax, 30
	mov c, ax
	mov ax, 0
	mov i, ax
	L5:
mov ax, i
	cmp ax, 3
	jl L0
	mov t0, 0
	jmp L1
	L0:
mov t0, 1
	L1:
	cmp t0, 1
	jne L6
	mov ax, i
	cmp ax, 0
	je L2
	mov t2, 0
	jmp L3
	L2:
mov t2, 1
	L3:
	mov ax, t2
	cmp ax, 0
	je L4
	mov ax, a
	call PRINTLN
	L4:

	MOV AX, i
	ADD AX, 1
	MOV i, AX
	mov ax, 
	mov i, ax
	L6:

	
	int 21h
	mov ah,4ch
	int 21h
main endp
end main
