#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10107
y = remote( host , port )

def echo( a , b , c ):
        y.sendafter( 'ice:' , '1' )




y.interactive()