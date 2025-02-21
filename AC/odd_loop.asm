

addi s0,x0,-1
li   s2,0
Loop:
	addi s0,s0,1	# counter+1
	li   t5,4	# offset multiplier
	mul  t6,s0,t5   # endereço + offset * 4
	add  t6,t6,a0   # mudança de endereço
	lw   s1,(t6)	# load do numero seguinte
	li   t6,2	# dois para o calculo do resto
	remu t0,s1,t6	# remainder
	add  s2,s2,t0	# soma dos remainders
	
	li   t6,49	# counter
	bne  s0,t6,Loop # loop
	add  a0,x0,s2	# resultado para x10