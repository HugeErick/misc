.data
    input_var:  .word 24        # Variable to store input value
    result:     .word 0       # Variable to store the result
    lab: .asciz "erick practica 6\n"
.text
_start:
    # Load word, ra0 input_var variable
    lw a0, input_var

    # Calculate the quadratic and store the result in a1
    mul a1, a0, a0

    # Store the result in the result variable
    la t0, result
    # saving word
    sw a1, 0(t0)

    # Exit the program
    li a7, 10        # System call for program exit
    ecall
