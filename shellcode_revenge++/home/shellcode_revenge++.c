#include<stdio.h>

char name[100];

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Name always contain printable characters, isn't it?" );
    puts( "What your name, ONLY contains [ 'a'~'z' 'A'~'Z' '0'~'9' ':' '>' '=' '<' '^' '_'  ]:");

    if( __read_chk( 0 , name , 99 , 100 ) <= 0 ){
        puts("read error");
        _exit(1);
    }

    printf('Hello %s! Leave some messege for me!' , name);
    char buf[0x10];
    read( 0 , buf , 0x20 );

    printf( "You said: %s" , buf );

    return 0;
}