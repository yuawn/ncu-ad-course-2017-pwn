#include<stdio.h>
#include<stdlib.h>

char code[16];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Give me your shellcode , I will execute it directly , but only 16 bytes :(");

    int (*yuawn)() = (int(*)())code;

    read( 0 , code , 16 );

    puts("Your shellcode is running...");
    yuawn();

    return 0;
}