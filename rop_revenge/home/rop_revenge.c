#include<stdio.h>

char name[0x70];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "What your name?" );

    read( 0 , name , 0x70 );

    char buf[0x20];
    read( 0  , buf , 0x30 );
    puts( "Only one gadget, Hacker go away~" );

    printf( "See you next time! %s\n" , name );

    return 0;
}