#include<stdio.h>

char name[16];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Give me your shellcode , I will run it directly , but only 16 bytes :(");

    int (*yuawn)() = (int(*)())name;

    read( 0 , name , 16 );

    yuawn();

    return 0;
}