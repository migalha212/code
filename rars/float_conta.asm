.data
A: .float 2.0
B: .float 1.0
C: .float 6.0
D: .float 3.0

.text
     la     t0, A
     la     t1, B
     la     t2, C
     la     t3, D
     flw    fa0,0(t0)
     flw    fa1,0(t1)
     flw    fa2,0(t2)
     flw    fa3,0(t3)
float:
     li       t4, -3
     fcvt.s.w ft3,t4  
     fsub.s ft0, fa0, fa1 
     fmul.s ft0, ft0,fa2
     fadd.s ft1, fa0,fa3
     fadd.s ft1, ft1,ft3
     fdiv.s ft0, ft0,ft1
     fcvt.w.s a0, ft0


