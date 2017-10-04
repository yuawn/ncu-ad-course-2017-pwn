#include<stdio.h>

char name[20];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Give me your shellcode , I will run it directly , but only 20 bytes :(\n");

    int (*yuawn)() = (int(*)())name;

    read( 0 , name , 20 );

    yuawn();

    return 0;
}