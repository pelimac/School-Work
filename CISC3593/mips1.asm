.data # variables stored here 
	num1: .word 7
	num2: .word 10
	
	

.text # code resides here
	lw $t0, num1 #loads in num1 from RAM
	lw $t1, num2 #loads in num2 from RAM	
	add $t2, $t0, $t1
