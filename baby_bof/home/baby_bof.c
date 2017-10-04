#include<stdio.h>

void you_cant_see_this_its_too_evil(){
    system("sh");
}

int main(){
    char buf[0x20];
    gets( buf );
    return 0;
}
