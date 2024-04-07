.data
lab:	.asciz "Erick practica 5\n"
array:  .word 4, 3, 6        # Our array to sort
size:   .word 3             # Size of the array

    .text
    .globl main
main:
    #la t3, lab 		    #print name
    la a0, array            # Load array address into a0
    lw a1, size             # Load array size into a1

outer_loop:
    li a2, 0                # Outer loop index i
    li a3, 1                # We start assuming no swaps to check for sorted array

inner_loop:
    bge a2, a1, end_sort    # Break if i >= array size
    lw t0, 0(a0)            # Load array[i]
    lw t1, 4(a0)            # Load array[i + 1]

    blt t0, t1, skip_swap   # Go to skip_swap if array[i] < array[i + 1]
    sw t1, 0(a0)            # Otherwise, swap array[i] and array[i + 1]
    sw t0, 4(a0)
    li a3, 0                # Indicate a swap occurred

skip_swap:
    addi a0, a0, 4          # Move to the next element
    addi a2, a2, 1          # Increment loop index
    j inner_loop            # Jump back to the start of the inner loop

end_sort:
    beqz a3, outer_loop     # If a swap occurred, repeat the sorting

    # End of sorting, place end program or result handling here

    # Exit simulation (RARS specific syscall)
    li a7, 10               # syscall number for exit
    ecall                   # Make syscall to exit program