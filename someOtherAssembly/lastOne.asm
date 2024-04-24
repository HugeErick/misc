# keyboardR rutine algorithm
# 1.- repit
# A.- row = 1 
# B.- key := -4
# C.- repit
# 	1.- select row
# 	2.- read cloumns
# 	3.- row := row * 2
# 	4.- key := key + 4
# D.- until key active or row = 0x10 (16)
# 	2.- until key detected
# 	3.- while key active
# A.- wait
# 	4.- column = 1
# 	5.- while (mData[column] = 0
# A column := column * 2
# B.- key := key + 1
# end
#===================================================================
#Constants
.eqv test 0xffff0012 # command row number of hexadecimal keyboard (bit 0 to 3) and enable keyboard interrupt (bit 7) 
.eqv getData 0xffff0014 # get row and column of keyboard
.eqv printString 4 # stdouts string
.eqv exitProgram 10 # exits the program
.eqv printInt 1 # print an int to console

.data
Lab:	.asciz "erick practica 8\n"
breakLinePls: .asciz "\n"
valScan: .word 0

.text
_start:
	la a0, Lab # load address of string Lab
	li a7, printString # loading code for ecall
	ecall
	call keyboardR
	call breakLine
	lw a0, valScan
	li t3, 10
	mul a2, t3, a0
	mv a0, a2
	li a7, printInt
	ecall
	call endMe # end program

# keyboardR rutine
# it waits until a key is pressed, then waits for it's release and id it
# input: none, output: 0 <= a6 <= 0xf; regs affected: a3, a4 & a5; 
keyboardR:
	li a3, 0x1
	li a6, -4
keyboardc:
	li a4, test
	sb a3, (a4)
	li a4, getData
	lb a5, (a4)
	add a3, a3, a3
	addi a6, a6, 4
	bnez a5, keyboard3
	andi a5, a3, 0x10
	beqz a5, keyboardc
	b keyboardR
keyboard3:
	lb a3, (a4)
	bnez a3 keyboard3
	li a3, 0x10
keyboard5:
	and a4, a3, a5
	bnez a4 keyboard6
	add a3, a3, a3
	addi a6, a6, 1
	b keyboard5
keyboard6:
	mv a0, a6
	li a7, printInt
	ecall
	sw, a6, valScan, a0 
	ret
breakLine:
	la a0, breakLinePls
	li a7, printString
	ecall
	ret
endMe:
	li a7, exitProgram
	ecall	
