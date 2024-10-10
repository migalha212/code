.data
X: .float 3.0,4.0,5.0
Y: .float 1.0,2.0,3.0

.text
main:
li	a2,3
j	prodint_VF
li      a7,10
ecall


prodint_VF:
addi 	sp,sp,-16
sw   	ra,12(sp)
la 	t0,X
la 	t1,Y
fcvt.d.w ft2,x0
mLoop: 
beqz    a2,end
flw	ft0,0(t0)
flw	ft1,0(t1)
addi	a2,a2,-1
fmadd.d ft2,ft0,ft1,ft2   # ft0 * ft1 + ft2
addi    t0,t0,4
addi    t1,t1,4
j	mLoop
end:
fcvt.w.d a0,ft2
lw 	ra,12(sp)
addi 	sp,sp,16
ret



