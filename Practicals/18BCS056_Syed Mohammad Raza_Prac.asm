	   LXI H,2000
	   MOV B,M
	   MVI D,01

FACT:	   CALL MULT
	   DCR B
	   JNZ FACT
	   INX H
	   MOV M,D
	   MVI D,07
	   INX H
	   MOV M,D
	   CALL DIV
	   HLT

DIV:	   LXI H,2001
	   MOV A,M
	   MVI C,00
	   INX H
	   MOV B,M

LOOP:	   CMP B
	   JC CARRY
	   SUB B
	   INR C
	   JMP LOOP

CARRY:	   STA 2050
	   MOV A,C
	   STA 2051
	   HLT

MULT:	   MOV E,B
	   MVI A,00

MULTLOOP:	   ADD D
	   DCR E
	   JNZ MULTLOOP
	   MOV D,A
	   RET
# ORG 2000H
# DB 04H
