global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy
;ajouter error exit
ft_strdup:
            call    ft_strlen
            inc     rax
            push    rdi
            mov     rdi, rax
            call    malloc
            cmp     rax, 0
            je      _exit
            mov     rdi, rax
            pop     rsi
            call    ft_strcpy
            ret

_exit:
        ret
