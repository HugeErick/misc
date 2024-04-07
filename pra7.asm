
# ================================================
# C-ish pseudocode
#	print(erick ...)
#	scan(a, b, c)
#	if ((0ba) & 1 == 0)
#	print(even)
#	else 
#	print(odd)
#	if ((0bb) & 1 == 0)
#	print(even)
#	else 
#	print(odd)
#	if ((0bc) & 1 == 0)
#	print(even)
#	else 
#	print(odd)
#
#	return 0



# declaration of constants 
.eqv readInt 5 # reads int from console
.eqv printInt 1 # print an int to console
.eqv printString 4 # stdouts string
.eqv exitProgram 10 # exits the program

.data
Lab:	.asciz "erick practica 7\n"

msg: .asciz "give me 3 digits to say if theyre odd or even\n"

oddMsg: .asciz "this num is odd\n"
evenMsg: .asciz "this num is even\n"

int1: .word 21 # allocating int with random value

	.text
_start:
	la a0, Lab # load address of string Lab
	li a7, printString # loading code for ecall
	ecall
	
	la a0, msg # load address of string msg
	li a7, printString # print the string
	ecall
	call scanInput
	call int1d
	call scanInput
	call int1d
	call scanInput
	call int1d
	call end















scanInput:
	la, a0, int1
	li a7, readInt # reads int from console
	ecall

	# rewrite int1 label with the int obtained
	mv a2, a0 # we need a temp register to rewrite the word int1 the int obtained
	sw, a0, int1, a2 # save word value of a2 to the loadded address corresponding to the label

	ret
#====================================================================
int1d:
	# tell if int1 is odd or even
	lw a0, int1    # Load the address of int1
	li t3, 1 # giving t3 the val of 1 
	and a2, a0, t3   # Perform bitwise AND operation with 1
	beqz a2, int1Even   # Branch if the result is zero (even)
	# Print odd message
	la a0, oddMsg   # Load the address of odd message
	li a7, printString  # Load the print string syscall code
	ecall
	j endInt1  # Jump to end
int1Even:
	# Print even message
	la a0, evenMsg   # Load the address of even message
	li a7, printString  # Load the print string syscall code
	ecall
	ret
endInt1:
	ret


end:
	li a7, exitProgram
	ecall
