#include<stdio.h>

void could_you_call_me(){
    system("cat /home/demo/flag");
}

int main(){
    setvbuf(stdout,0,2,0);
    puts("Flag is my secrete, I wont give it to you :D");

    char buf[16];
    gets( buf );

    return 0;
}