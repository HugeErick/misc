Lab:
	.data
	.asciz "erick practica 6\n"
	.eqv Disp_0 0xffff0010 #right display
	.eqv Test_disp 0xFF # total turn on state
	.eqv Off_Disp 0 # total turn off state
X:	
	.word 15
Decoder:
	.word 0x3f # 0
	.word 0x06 # 1
	.word 0x5b # 2
	.word 0x4f # 3
	.word 0x66 # 4
	.word 0x6d # 5
	.word 0x7d # 6
	.word 0x07 # 7
	.word 0x7f # 8
	.word 0x67 # 9
	.word 0x77 # A
	.word 0x7c # B
	.word 0x39 # C
	.word 0x5e # D
	.word 0x79 # E
	.word 0x71 # F
	
	.text
_start:
	la a0, Lab
	
	# Turn on (all)
	li x4, Disp_0
	li x3, Test_disp
	sw x3, (x4)
	
	# Turn off (all)
	li x3, Off_Disp
	sw x3, (x4)
	
	# Display X
	la x3, Decoder # x3 pointer to decodificador
	lw x4, X # x4 is X (the val to display)
	andi x4 x4 0xF # Mask 4 last bits
	add x3 x3 x4 # x3 := Decoder + 4 * x4
	add x3 x3 x4
	add x3 x3 x4
	add x3 x3 x4
	lw x3, (x3) # code to be showe 
	li x4, Disp_0 # select display
	sw x3, (x4) # Turn on
_end:
	#exit
	li a7, 10
	ecall

	
