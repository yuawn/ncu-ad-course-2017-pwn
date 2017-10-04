#include<stdio.h>
#include<stdlib.h>

int main(){
    setvbuf(stdout,0,2,0);
    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed); //init

    puts("GOOD LUCK:");

    char something[8];
    int password = random();
    int a = 0 , b = 1;

    puts( "What do you want to tell me:" );
    read( 0 , something , 100 );

    if( a == 0xfaceb00c && b == 0xdeadbeef ){
        puts( "Hello hacker, now guess the password." );
        puts( "A good hacker always 100% guess right :P, are you a good hacker?" );
        printf( "password:" );

        int input;
        scanf( "%d" , &input );

        if( input == password ){
            puts( "Here is your shell!" );
            system( "sh" );
        }
        else{
            puts( "Bye Muggle :(" );
            exit(0);
        }
    }

    return 0;
}