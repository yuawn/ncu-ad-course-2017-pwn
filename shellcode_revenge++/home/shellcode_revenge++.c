#include<stdio.h>

char code[10];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Give me your shellcode , I will execute it directly , but only 10 bytes :(");

    int (*yuawn)() = (int(*)())code;

    read( 0 , code , 10 );

    puts("Your shellcode is running...");
    yuawn();

    return 0;
}