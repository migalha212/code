check_nan:
 addi sp,sp,-16
 sw   ra,0(sp)
 xor a0,a0,a1
 srli a0,a0,31
 lw ra,0(sp)
 addi sp,sp,16
 ret
 