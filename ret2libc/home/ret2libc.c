#include<stdio.h>
//#include<stdlib.h>

int main(){
    setvbuf(stdout,0,2,0);
    printf( "Where do you want to see in the memory? Give me the address in decimal:" );
    long *p;
    scanf( "%ld" , &p );
    printf( "The value in memory at %p is %p.\n" , p , *p );

    puts("Bypass the check, and ret2libcccccccccccc");

    char buf[10];
    read( 0 , buf , 200 );
    
    if( strlen( buf ) > 6 ) {
        puts( "It could not > 6. If you want the flag, Over my dead body!!!!!" );
        exit(0);
    }

    return 0;
}