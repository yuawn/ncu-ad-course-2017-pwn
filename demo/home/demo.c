#include<stdio.h>

void could_you_call_me(){
    system("cat /home/deno/flag");
    //fflush(stdout);
}

int main(){
    puts("Flag is my secrete, I wont give it to you :D");
    fflush(stdout);

    char buf[16];
    gets( buf );

    return 0;
}