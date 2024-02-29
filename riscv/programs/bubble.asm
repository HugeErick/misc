    .data
numbers: .word 4, 3, 6, 7  # The numbers to be sorted
    .text
    .globl main
main:
    la a0, numbers  # Load the address of the numbers
    li a1, 4  # The number of elements in the array
    jal ra, bubble_sort  # Call the bubble sort function
    li a7, 10  # Exit system call
    ecall  # Make the system call

bubble_sort:
    addi sp, sp, -20  # Allocate space on the stack for the saved registers
    sw ra, 16(sp)  # Save the return address
    sw a0, 12(sp)  # Save the array pointer
    sw a1, 8(sp)  # Save the array length
    sw a2, 4(sp)  # Save the temporary register
    sw a3, 0(sp) # save the swap flag
    loop:
        lw a1, 8(sp)  # Load the array length
        addi a1, a1, -1  # Decrement the array length
        sw a1, 4(sp)  # Save the new array length
        li a2, 0  # Initialize the index to 0
        li a3, 0  # Initialize the swap flag to 0
        inner_loop:
            lw a0, 12(sp)  # Load the array pointer
            add a4, a0, a2  # Calculate the address of the current element
            lw a5, 0(a4)  # Load the current element
            lw a6, 4(a4)  # Load the next element
            blt a6, a5, swap  # If the next element is less than the current, swap them
            addi a2, a2, 4  # Increment the index
            lw a1, 8(sp)  # Load the array length
            blt a2, a1, inner_loop  # If the index is less than the array length, continue the inner loop
        lw a3, 0(sp)  # Load the swap flag
        beqz a3, end  # If no swaps occurred, end the sort
        j loop  # Continue the outer loop
    swap:
        sw a5, 4(a4)  # Swap the current element and the next element
        sw a6, 0(a4)
        li a3, 1  # Set the swap flag to 1
        sw a3, 0(sp)  # Save the swap flag
        j inner_loop  # Continue the inner loop
    end:
    	lw ra, 16(sp)  # Restore the return address
        addi sp, sp, 20  # Deallocate the stack space
        jr ra  # Return from the function