global _ft_read
extern ___error

_ft_read:
            mov		rax, 0x2000003
	        syscall
	        jnc     _end
	        push    rax
	        call    ___error
	        pop     qword [rax]
            mov     rax, -1

_end:
            ret