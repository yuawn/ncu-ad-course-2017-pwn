#include<stdio.h>

char name[0x280];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "What your name?" );

    read( 0 , name , 0x280 );
    printf( "Hello! %s\nWhat do you want to say?\n" , name );

    
    char buf[0x20];
    read( 0  , buf , 0x30 );
    puts( "Only one gadget, Hacker go away~" );

    return 0;
}