#include<stdio.h>

void you_cant_see_this_its_too_evil(){
    system("sh");
}

int main(){
    setvbuf(stdout,0,2,0);
    puts("Welcome to NCU AD 2017 Fall, Im yuawn :)");

    char buf[20];
    gets( buf );

    return 0;
}
