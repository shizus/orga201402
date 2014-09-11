	.file	1 "main.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC1:
	.ascii	"help\000"
	.align	2
$LC2:
	.ascii	"number-separator\000"
	.align	2
$LC3:
	.ascii	"starting-line-number\000"
	.align	2
$LC4:
	.ascii	"line-increment\000"
	.align	2
$LC5:
	.ascii	"non-empty\000"
	.align	2
$LC6:
	.ascii	"join-blank-lines\000"
	.data
	.align	2
$LC7:
	.word	$LC1
	.word	0
	.word	0
	.word	104
	.word	$LC2
	.word	2
	.word	0
	.word	115
	.word	$LC3
	.word	2
	.word	0
	.word	118
	.word	$LC4
	.word	2
	.word	0
	.word	105
	.word	$LC5
	.word	2
	.word	0
	.word	116
	.word	$LC6
	.word	2
	.word	0
	.word	108
	.word	0
	.word	0
	.word	0
	.word	0
	.globl	memcpy
	.rdata
	.align	2
$LC0:
	.ascii	"hs:v:i:tl:\000"
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,208,$ra		# vars= 160, regs= 3/0, args= 24, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,208
	.cprestore 24
	sw	$ra,200($sp)
	sw	$fp,196($sp)
	sw	$gp,192($sp)
	move	$fp,$sp
	sw	$a0,208($fp)
	sw	$a1,212($fp)
	sw	$zero,52($fp)
	sw	$zero,56($fp)
	sw	$zero,60($fp)
	li	$v0,1			# 0x1
	sw	$v0,64($fp)
	li	$v0,1			# 0x1
	sw	$v0,40($fp)
	li	$v0,1			# 0x1
	sw	$v0,36($fp)
	la	$v0,$LC0
	sw	$v0,68($fp)
	addu	$v0,$fp,72
	la	$v1,$LC7
	move	$a0,$v0
	move	$a1,$v1
	li	$a2,112			# 0x70
	la	$t9,memcpy
	jal	$ra,$t9
$L18:
	addu	$v0,$fp,72
	sw	$zero,16($sp)
	lw	$a0,208($fp)
	lw	$a1,212($fp)
	lw	$a2,68($fp)
	move	$a3,$v0
	la	$t9,getopt_long
	jal	$ra,$t9
	sw	$v0,48($fp)
	lw	$v1,48($fp)
	li	$v0,-1			# 0xffffffffffffffff
	bne	$v1,$v0,$L21
	b	$L19
$L21:
	lw	$v0,48($fp)
	sw	$v0,184($fp)
	li	$v0,108			# 0x6c
	lw	$v1,184($fp)
	beq	$v1,$v0,$L28
	lw	$v1,184($fp)
	slt	$v0,$v1,109
	beq	$v0,$zero,$L33
	li	$v0,104			# 0x68
	lw	$v1,184($fp)
	beq	$v1,$v0,$L23
	lw	$v1,184($fp)
	slt	$v0,$v1,105
	beq	$v0,$zero,$L34
	li	$v0,-1			# 0xffffffffffffffff
	lw	$v1,184($fp)
	beq	$v1,$v0,$L18
	li	$v0,63			# 0x3f
	lw	$v1,184($fp)
	beq	$v1,$v0,$L29
	b	$L31
$L34:
	li	$v0,105			# 0x69
	lw	$v1,184($fp)
	beq	$v1,$v0,$L26
	b	$L31
$L33:
	li	$v0,116			# 0x74
	lw	$v1,184($fp)
	beq	$v1,$v0,$L27
	lw	$v1,184($fp)
	slt	$v0,$v1,117
	beq	$v0,$zero,$L35
	li	$v0,115			# 0x73
	lw	$v1,184($fp)
	beq	$v1,$v0,$L24
	b	$L31
$L35:
	li	$v0,118			# 0x76
	lw	$v1,184($fp)
	beq	$v1,$v0,$L25
	b	$L31
$L23:
	la	$t9,imprime_uso
	jal	$ra,$t9
	move	$a0,$zero
	la	$t9,exit
	jal	$ra,$t9
$L24:
	lw	$v0,optarg
	sw	$v0,60($fp)
	b	$L18
$L25:
	lw	$a0,optarg
	la	$t9,atoi
	jal	$ra,$t9
	sw	$v0,36($fp)
	b	$L18
$L26:
	lw	$a0,optarg
	la	$t9,atoi
	jal	$ra,$t9
	sw	$v0,40($fp)
	b	$L18
$L27:
	sw	$zero,64($fp)
	b	$L18
$L28:
	lw	$a0,optarg
	la	$t9,atoi
	jal	$ra,$t9
	sw	$v0,44($fp)
	b	$L18
$L29:
	la	$t9,imprime_uso
	jal	$ra,$t9
	li	$a0,1			# 0x1
	la	$t9,exit
	jal	$ra,$t9
$L31:
	li	$a0,1			# 0x1
	la	$t9,exit
	jal	$ra,$t9
$L19:
	lw	$v0,optind
	sw	$v0,32($fp)
	lw	$v1,32($fp)
	lw	$v0,208($fp)
	bne	$v1,$v0,$L36
	sw	$zero,56($fp)
	lw	$v0,44($fp)
	sw	$v0,16($sp)
	lw	$v0,32($fp)
	sll	$v1,$v0,2
	lw	$v0,212($fp)
	addu	$v0,$v1,$v0
	lw	$v0,0($v0)
	sw	$v0,20($sp)
	lw	$a0,60($fp)
	lw	$a1,36($fp)
	lw	$a2,40($fp)
	lw	$a3,64($fp)
	la	$t9,procesarArchivo
	jal	$ra,$t9
	b	$L37
$L36:
	lw	$v0,optind
	sw	$v0,32($fp)
$L38:
	lw	$v0,32($fp)
	lw	$v1,208($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L41
	b	$L37
$L41:
	lw	$v0,44($fp)
	sw	$v0,16($sp)
	lw	$v0,32($fp)
	sll	$v1,$v0,2
	lw	$v0,212($fp)
	addu	$v0,$v1,$v0
	lw	$v0,0($v0)
	sw	$v0,20($sp)
	lw	$a0,60($fp)
	lw	$a1,36($fp)
	lw	$a2,40($fp)
	lw	$a3,64($fp)
	la	$t9,procesarArchivo
	jal	$ra,$t9
	lw	$v0,32($fp)
	addu	$v0,$v0,1
	sw	$v0,32($fp)
	b	$L38
$L37:
	move	$v0,$zero
	move	$sp,$fp
	lw	$ra,200($sp)
	lw	$fp,196($sp)
	addu	$sp,$sp,208
	j	$ra
	.end	main
	.size	main, .-main
	.rdata
	.align	2
$LC8:
	.ascii	"r\000"
	.align	2
$LC9:
	.ascii	"%i%s \000"
	.align	2
$LC10:
	.ascii	"\n\000"
	.align	2
$LC11:
	.ascii	"%i%s \n\000"
	.align	2
$LC12:
	.ascii	"%c\000"
	.text
	.align	2
	.globl	procesarArchivo
	.ent	procesarArchivo
procesarArchivo:
	.frame	$fp,72,$ra		# vars= 32, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,72
	.cprestore 16
	sw	$ra,64($sp)
	sw	$fp,60($sp)
	sw	$gp,56($sp)
	move	$fp,$sp
	sw	$a0,72($fp)
	sw	$a1,76($fp)
	sw	$a2,80($fp)
	sw	$a3,84($fp)
	sw	$zero,24($fp)
	lw	$v0,88($fp)
	bne	$v0,$zero,$L43
	li	$v0,1			# 0x1
	sw	$v0,88($fp)
$L43:
	lw	$v0,76($fp)
	bne	$v0,$zero,$L44
	li	$v0,1			# 0x1
	sw	$v0,76($fp)
$L44:
	lw	$v0,80($fp)
	bne	$v0,$zero,$L45
	li	$v0,1			# 0x1
	sw	$v0,80($fp)
$L45:
	lw	$v0,92($fp)
	bne	$v0,$zero,$L46
	la	$v0,__sF
	sw	$v0,24($fp)
	b	$L47
$L46:
	lw	$a0,92($fp)
	la	$a1,$LC8
	la	$t9,fopen
	jal	$ra,$t9
	sw	$v0,24($fp)
$L47:
	sw	$zero,32($fp)
	lw	$v0,76($fp)
	sw	$v0,36($fp)
	sw	$zero,40($fp)
	sw	$zero,44($fp)
$L48:
	lw	$v1,24($fp)
	lw	$v0,24($fp)
	lw	$v0,4($v0)
	addu	$v0,$v0,-1
	sw	$v0,4($v1)
	bgez	$v0,$L51
	lw	$a0,24($fp)
	la	$t9,__srget
	jal	$ra,$t9
	sb	$v0,52($fp)
	b	$L52
$L51:
	lw	$v0,24($fp)
	lw	$v1,0($v0)
	move	$a0,$v1
	lbu	$a0,0($a0)
	sb	$a0,52($fp)
	addu	$v1,$v1,1
	sw	$v1,0($v0)
$L52:
	lbu	$v0,52($fp)
	sb	$v0,28($fp)
	sll	$v0,$v0,24
	sra	$v1,$v0,24
	li	$v0,-1			# 0xffffffffffffffff
	bne	$v1,$v0,$L50
	b	$L49
$L50:
	lw	$v0,32($fp)
	bne	$v0,$zero,$L53
	li	$v0,1			# 0x1
	sw	$v0,32($fp)
	la	$a0,$LC9
	lw	$a1,36($fp)
	lw	$a2,72($fp)
	la	$t9,printf
	jal	$ra,$t9
$L53:
	lb	$v1,28($fp)
	li	$v0,10			# 0xa
	bne	$v1,$v0,$L54
	lw	$v1,84($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L55
	lw	$v1,40($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L56
	lw	$v1,44($fp)
	lw	$v0,88($fp)
	bne	$v1,$v0,$L57
	la	$a0,$LC9
	lw	$a1,36($fp)
	lw	$a2,72($fp)
	la	$t9,printf
	jal	$ra,$t9
	la	$a0,$LC10
	la	$t9,printf
	jal	$ra,$t9
	lw	$v1,36($fp)
	lw	$v0,80($fp)
	addu	$v0,$v1,$v0
	sw	$v0,36($fp)
	li	$v0,1			# 0x1
	sw	$v0,44($fp)
	b	$L48
$L57:
	lw	$v0,44($fp)
	addu	$v0,$v0,1
	sw	$v0,44($fp)
	b	$L48
$L56:
	lw	$v1,44($fp)
	lw	$v0,88($fp)
	bne	$v1,$v0,$L60
	la	$a0,$LC10
	la	$t9,printf
	jal	$ra,$t9
	lw	$v1,36($fp)
	lw	$v0,80($fp)
	addu	$v0,$v1,$v0
	sw	$v0,36($fp)
	li	$v0,1			# 0x1
	sw	$v0,40($fp)
	li	$v0,1			# 0x1
	sw	$v0,44($fp)
	b	$L48
$L60:
	lw	$v0,44($fp)
	addu	$v0,$v0,1
	sw	$v0,44($fp)
	lw	$v1,44($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L48
	la	$a0,$LC10
	la	$t9,printf
	jal	$ra,$t9
	li	$v0,1			# 0x1
	sw	$v0,40($fp)
	lw	$v1,36($fp)
	lw	$v0,80($fp)
	addu	$v0,$v1,$v0
	sw	$v0,36($fp)
	b	$L48
$L55:
	lw	$v1,44($fp)
	lw	$v0,88($fp)
	bne	$v1,$v0,$L64
	la	$a0,$LC10
	la	$t9,printf
	jal	$ra,$t9
	lw	$v0,40($fp)
	bne	$v0,$zero,$L65
	lw	$v0,36($fp)
	lw	$v1,80($fp)
	addu	$v0,$v0,$v1
	sw	$v0,36($fp)
$L65:
	li	$v0,1			# 0x1
	sw	$v0,40($fp)
	li	$v0,1			# 0x1
	sw	$v0,44($fp)
	b	$L48
$L64:
	lw	$v0,44($fp)
	addu	$v0,$v0,1
	sw	$v0,44($fp)
	lw	$v1,44($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L48
	la	$a0,$LC10
	la	$t9,printf
	jal	$ra,$t9
	li	$v0,1			# 0x1
	sw	$v0,40($fp)
	lw	$v1,36($fp)
	lw	$v0,80($fp)
	addu	$v0,$v1,$v0
	sw	$v0,36($fp)
	b	$L48
$L54:
	lw	$v0,44($fp)
	slt	$v0,$v0,2
	bne	$v0,$zero,$L69
	lw	$v1,84($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L70
	li	$v0,1			# 0x1
	sw	$v0,48($fp)
	li	$v0,1			# 0x1
	sw	$v0,48($fp)
$L71:
	lw	$v0,48($fp)
	lw	$v1,44($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L74
	b	$L72
$L74:
	la	$a0,$LC11
	lw	$a1,36($fp)
	lw	$a2,72($fp)
	la	$t9,printf
	jal	$ra,$t9
	lw	$v1,36($fp)
	lw	$v0,80($fp)
	addu	$v0,$v1,$v0
	sw	$v0,36($fp)
	lw	$v0,48($fp)
	addu	$v0,$v0,1
	sw	$v0,48($fp)
	b	$L71
$L72:
	sw	$zero,44($fp)
	b	$L69
$L70:
	li	$v0,1			# 0x1
	sw	$v0,48($fp)
	li	$v0,1			# 0x1
	sw	$v0,48($fp)
$L76:
	lw	$v0,48($fp)
	lw	$v1,44($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L79
	b	$L77
$L79:
	la	$a0,$LC10
	la	$t9,printf
	jal	$ra,$t9
	li	$v0,1			# 0x1
	sw	$v0,40($fp)
	lw	$v0,48($fp)
	addu	$v0,$v0,1
	sw	$v0,48($fp)
	b	$L76
$L77:
	sw	$zero,44($fp)
$L69:
	lw	$v1,40($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L80
	sw	$zero,40($fp)
	la	$a0,$LC9
	lw	$a1,36($fp)
	lw	$a2,72($fp)
	la	$t9,printf
	jal	$ra,$t9
	sw	$zero,44($fp)
$L80:
	lb	$v0,28($fp)
	la	$a0,$LC12
	move	$a1,$v0
	la	$t9,printf
	jal	$ra,$t9
	b	$L48
$L49:
	lw	$a0,24($fp)
	la	$t9,fclose
	jal	$ra,$t9
	move	$sp,$fp
	lw	$ra,64($sp)
	lw	$fp,60($sp)
	addu	$sp,$sp,72
	j	$ra
	.end	procesarArchivo
	.size	procesarArchivo, .-procesarArchivo
	.rdata
	.align	2
$LC13:
	.ascii	"USAGE:\n"
	.ascii	"tp0 [OPTION]...[FILE]...\n"
	.ascii	"Write each FILE to standard output, with line numbers ad"
	.ascii	"ded. With no FILE, or when FILE ir -,\n"
	.ascii	"read standard input\n\n"
	.ascii	"OPTIONS:\n"
	.ascii	"-h, --help Print this message and quit\n"
	.ascii	"-s, --number-separator (mandatory argument)\n"
	.ascii	"-v, --starting-line-number (mandatory argument)\n"
	.ascii	"-i, --line-increment (mandatory argument)\n"
	.ascii	"-l, --join-blank-lines (mandatory argument)\n"
	.ascii	"-t, --non-empty\n\000"
	.text
	.align	2
	.globl	imprime_uso
	.ent	imprime_uso
imprime_uso:
	.frame	$fp,40,$ra		# vars= 0, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,40
	.cprestore 16
	sw	$ra,32($sp)
	sw	$fp,28($sp)
	sw	$gp,24($sp)
	move	$fp,$sp
	la	$a0,$LC13
	la	$t9,printf
	jal	$ra,$t9
	move	$sp,$fp
	lw	$ra,32($sp)
	lw	$fp,28($sp)
	addu	$sp,$sp,40
	j	$ra
	.end	imprime_uso
	.size	imprime_uso, .-imprime_uso
	.ident	"GCC: (GNU) 3.3.3 (NetBSD nb3 20040520)"
