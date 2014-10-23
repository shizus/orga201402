#	Tp1 2do cuatrimestre 2014
#	Funcion:
#	int validate ( char * text, char **errmsg);
#
################
# Stack frame: #
################
# 32 ------------
#	PADDING
# 28 ------------
#	ra
# 24 ------------
#	fp
# 20 ------------
#	gp
# 16 ------------
#	PADDING
# 12 ------------
#	PADDING
# 8 ------------
#	A1
# 4 ------------
#	A0
# 0 ------------
#
#
################################
# Detalle de registros usados: #
################################
#	a0: parametro char * text
#	a1: parametro char ** errmsg
#	t0: 
#	t1: 
#	t2: 
#	t3: 
#
#	t6: temporal usada para calculos
#	t7: temporal usada para calculos
#	t8: temporal usada para calculos
#	t9: temporal usada para calculos
#
#define SF_SIZE 	32
#define RA		24
#define FP		20
#define GP		16
#define A1		4
#define A0		0
#
#include <mips/regdef.h>
#include <sys/syscall.h>
#
		.text   		#comienzo del código
		.align 2		#alineacion 2^2
		
		.set noreorder
		.cpload t9
		.set reorder
		
		.globl validate 	#funcion publica
		.ent validate		#punto de entrada de la funcion


validate:
		subu 	sp, sp, SF_SIZE		# creo stack frame
		sw 	$fp, FP(sp)		# guardo valor de fp
		sw 	gp, GP(sp)		# guardo valor de gp
		sw 	ra, RA(sp)		# guardo valor de ra
		move 	$fp, sp

		sw 	a0, A0(sp)		# cargo parametro char * text en t0
		sw 	a1, A1(sp)		# cargo parametro char ** errmsg en t1

#		la a0,texto
#		la t9,printf
#		jal t9

#		la a0,texto
#		jal strlen

#		addu a1,zero,v0
#		la a0,entero
#		jal printf

		la a0,tag
		la a1,texto
		jal mystrcpy
		
#		la t2, tag
#		lb t1,0(t2)
#		addi t1,zero,64
#		sb t1,0(t2)

		la a0,tag
		jal printf
		j fin		
mystrcpy:
		lb t0,0(a1)
		addi a1,a1,1
		sb t0,0(a0)
		addi a0,a0,1
		bnez t0,mystrcpy
		jr ra


fin:
		lw ra,RA(sp)		#Cargado de parametros y 
		lw $fp,FP(sp)		#destruccion del stack validate
		lw gp,GP(sp)
		lw a0,A0(sp)
		lw a1,A1(sp)
	
		addu sp,sp,32
		#TODO:modificar la salida
		li v0,0	
		j ra


.end validate


###########DATOS###############
		.data
texto:		.asciiz "af"
ABIERTO:	.asciiz "<"
CERRADO:	.asciiz ">"
posApertura:	.word '0'
posCierre: 	.word '0'
resultado:	.word '0'
lineaError:	.word '0'
contadorTags:	.word '0'
tag:	.space 20

entero:
	.asciiz "%d"

#	char  vTag[20][10];
#	char tag[10]="";

