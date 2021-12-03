	.data 
	.word
  
blink_count:
	.text
	.word default
	.word mod1
	.word mod2
	.word mod3
  
jt:	
	.global wdt_c_handler
  
wdt_c_handler:
	add #1, &blink_count
	mov &mode, r12
	cmp #3, r2
	jnc default
	add r12, r12
	mov jt(r12), r0

mod1:
	mov &mode, r12
	call #act1
	jmp end
	
mod2:
	mov &mode, r12
	call #act2
	jmp end
  
mod3:
	mov &mode, r12
	call #act3
	jmp end
	
default:
	mov #0, &mode
  
end:
	pop r0
