#include<stdio.h>

int main(){
    setvbuf(stdout,0,2,0);

    char buf[100];
    printf( "Your input buffer address is %p" , buf );

    read( 0 , buf , 116 );

    return 0;
}