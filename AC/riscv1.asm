.data
nums:  .word   17,24,18
var:   .half   9,-1,15 
str1:  .byte   45,47,49
str2:  .asciz  "my string"
stuff: .space  20

.text			#text
la x5, nums 		# x5 has nums' address 
lw x10, 0(x5) 
lh x7, var		# x7 is assigned 9

L1: beqz, x7, L2	#while loop is real
 addi x7,x7,-1		# x7 - 1
 b L1			# back to the loop
L2: 
nop 

#leaf_example:
#	add a0,a0,a1
#	add a2,a2,a3
#	sub a0,a0,a2
#	ret