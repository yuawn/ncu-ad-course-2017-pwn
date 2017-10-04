#include<stdio.h>

void could_you_call_me(){
    system("cat ./flag");
}

int main(){
    put("Flag is my secrete, I wont give it to you :D");
    char buf[0x20];
    gets( buf );
    return 0;
}
