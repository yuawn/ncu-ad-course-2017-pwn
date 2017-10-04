#include<stdio.h>
#include<stdlib.h>

char code[16];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Give me your shellcode , I will execute it directly , but only 16 bytes :(");

    int (*yuawn)() = (int(*)())code;

    char input[100];

    int len = read( 0 , input , 100 );

    if( len > 16 ){
        printf( "Your input size is %d , only 16 bytes!\n" );
        exit(0);
    }

    memcpy( code , input , sizeof( code ) );
    puts("Your shellcode is running...");
    yuawn();

    return 0;
}