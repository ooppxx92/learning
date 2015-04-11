	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"server.cpp"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"socket\000"
	.align	2
.LC1:
	.ascii	"bind\000"
	.align	2
.LC2:
	.ascii	"listen\000"
	.align	2
.LC3:
	.ascii	"accept\000"
	.align	2
.LC4:
	.ascii	"server:got connection from %s\012\000"
	.align	2
.LC5:
	.ascii	"Hello,world!\012\000"
	.align	2
.LC6:
	.ascii	"send\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	.fnstart
.LFB0:
	@ args = 0, pretend = 0, frame = 48
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
	.setfp fp, sp, #4
	add	fp, sp, #4
	.pad #48
	sub	sp, sp, #48
	mov	r0, #2
	mov	r1, #1
	mov	r2, #0
	bl	socket
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmn	r3, #1
	movne	r3, #0
	moveq	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L2
	ldr	r0, .L10
	bl	perror
	mov	r0, #1
	bl	exit
.L2:
	mov	r3, #2
	strh	r3, [fp, #-28]	@ movhi
	ldr	r0, .L10+4
	bl	htons
	mov	r3, r0
	strh	r3, [fp, #-26]	@ movhi
	mov	r3, #0
	str	r3, [fp, #-24]
	sub	r3, fp, #28
	add	r3, r3, #8
	mov	r2, #0
	str	r2, [r3, #0]
	mov	r2, #0
	str	r2, [r3, #4]
	sub	r3, fp, #28
	ldr	r0, [fp, #-8]
	mov	r1, r3
	mov	r2, #16
	bl	bind
	mov	r3, r0
	cmn	r3, #1
	movne	r3, #0
	moveq	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L3
	ldr	r0, .L10+8
	bl	perror
	mov	r0, #1
	bl	exit
.L3:
	ldr	r0, [fp, #-8]
	mov	r1, #10
	bl	listen
	mov	r3, r0
	cmn	r3, #1
	movne	r3, #0
	moveq	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L4
	ldr	r0, .L10+12
	bl	perror
	mov	r0, #1
	bl	exit
.L4:
	mov	r3, #16
	str	r3, [fp, #-48]
	sub	r2, fp, #44
	sub	r3, fp, #48
	ldr	r0, [fp, #-8]
	mov	r1, r2
	mov	r2, r3
	bl	accept
	mov	r3, r0
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmn	r3, #1
	movne	r3, #0
	moveq	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L5
	ldr	r0, .L10+16
	bl	printf
	mov	r0, r0	@ nop
	b	.L4
.L5:
	ldr	r0, [fp, #-40]
	bl	inet_ntoa
	mov	r3, r0
	ldr	r0, .L10+20
	mov	r1, r3
	bl	printf
	bl	fork
	mov	r3, r0
	cmp	r3, #0
	movne	r3, #0
	moveq	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L7
	ldr	r0, [fp, #-12]
	ldr	r1, .L10+24
	mov	r2, #14
	mov	r3, #0
	bl	send
	mov	r3, r0
	cmn	r3, #1
	movne	r3, #0
	moveq	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L8
	ldr	r0, .L10+28
	bl	perror
.L8:
	ldr	r0, [fp, #-12]
	bl	close
	mov	r0, #0
	bl	exit
.L7:
	ldr	r0, [fp, #-12]
	bl	close
	mov	r0, r0	@ nop
.L9:
	mvn	r0, #0
	mov	r1, #0
	mov	r2, #1
	bl	waitpid
	mov	r3, r0
	cmp	r3, #0
	movle	r3, #0
	movgt	r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L9
	b	.L4
.L11:
	.align	2
.L10:
	.word	.LC0
	.word	3333
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.fnend
	.size	main, .-main
	.ident	"GCC: (Debian 4.6.3-14+rpi1) 4.6.3"
	.section	.note.GNU-stack,"",%progbits
