.model small
.stack 100h
.data

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
	mov es,ax
	int 21h
	mov ah,4ch
	int 21h
main endp
end main

