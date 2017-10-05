#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10107
y = remote( host , port )

def echo( data ):
        y.sendafter( 'ice:' , '1' )
        y.sendafter( 'say:' , data )

def add( data , idx ):
        y.sendafter( 'ice:' , '2' )
        y.sendafter( '?:' , str( idx ) )
        y.sendafter( ':' , data )

def add( data , idx ):
        y.sendafter( 'ice:' , '3' )
        y.sendafter( '?:' , str( idx ) )





y.interactive()