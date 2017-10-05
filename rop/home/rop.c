#include<stdio.h>

int main(){
    setvbuf(stdout,0,2,0);
    puts( "ROP attack is easy, isn't it? Show me your skill." );

    char buf[0x20];
    read( 0  , buf , 200 );

    return 0;
}