#include<stdio.h>
#include<stdlib.h>

int main(){
    setvbuf(stdout,0,2,0);
    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed); //init

    puts("GOOD LUCK:");

    int a = 0 , b = 1 , c = 2;
    int password = random();

    puts( "What do you want to tell me:" );
    read( 0 , &a , 100 );
    
    printf("You say: %s\n" , &a);

    if( b == 0xfaceb00c && c == 0xdeadbeef ){
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
            puts( "Bad Luck :(" );
            exit(0);
        }
    }

    puts( "Bye Muggle :(" );
    exit(0);

    return 0;
}