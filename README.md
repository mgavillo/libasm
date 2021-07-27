# libasm
This school project's goal is to create a basic asm library. 

## Table of Contents  
[ft_strlen](#strlen)

[ft_strcpy](#strcpy)

[ft_strcmp](#strcmp)

[ft_write](#write)

[ft_read](#read)

[ft_strdup](#strdup)


[ft_atoi_base](#atoi_base)

[ft_list_push_front](#list_push_front)

[ft_list_size](#list_size)

[ft_list_sort](#list_sort)

[ft_list_remove_if](#list_remove_if)

## Prenambule
This code is made in 64 bits ASM with Intel syntax.

### Registers
| Registers                                                           | Size                   |
| ------------------------------------------------------------------- |:----------------------:|
| rax , rbx , rcx , rdx , rdi , rsi , rbp, rsp , r8 , r9 , ... , r15  | 64 bits                |
| eax, ebx, ecx, edx, edi , esi , ebp, esp, r8d, r9d, ... , r15d      | 32 bits                |
| ax, bx, cx, dx, di , si , bp, sp , r8w, r9w, ... , r15w             | 16 bits (15:0)         |
| ah, bh, ch, dh                                                      | 8 bits high (15:8)     |
| al , bl , cl , dl , dil , sil , bpl , spl , r8b, r9b, ... , r15b    | 8 bits low (7:0)       |


### Instructions

| instruction         | explanation                               |       | Possible sizes name | size              | c equivalent |
| ------------------- |:-----------------------------------------:|       | ------------------- |:-----------------:|:------------:|
| mov (size) dest,src | dest ←src                                 |       | byte                | 1 octet           | char         |
| movzx dest,src      | fills the blanks with 0                   |       | word                | 2 octets ou 1 mot | short        |
                                                                          | dword               | 4 octets          | int          |
                                                                          | qword               | 8 octets          | long         |
                                                                          | tword               | 10 octets         |              |

## Tests
You can test this library with the main made in C. This whill also test the errno variable after a syscall.
Just run `make test`.
