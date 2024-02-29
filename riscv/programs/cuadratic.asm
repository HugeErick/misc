.data
    input_var:  .word 5        # Variable to store input value
    result:     .word 0       # Variable to store the result

.text
.globl _start

_start:

    # Load the input value into register a0
    lw a0, input_var

    # Calculate the quadratic and store the result in a1
    mul a1, a0, a0

    # Store the result in the result variable
    la t0, result
    sw a1, 0(t0)

    # Exit the program
    li a7, 10        # System call for program exit
    ecall
