#include<stdio.h>
#include<stdlib.h>

void menu(){
    puts( "---------------------------" );
    puts( "1. echo server" );
    puts( "2. store memo" );
    puts( "3. show memo" );
    puts( "4. edit memo" );
    puts( "5. exit" );
    puts( "---------------------------" );
    puts( "Your choice:" );
}

int read_int(){
    char buf[16];
    if( __read_chk(0,buf,15,16) <= 0 ){
        puts("read error");
        _exit(1);
    }
    return atoi(buf);
}


void echo(){
    char s[0x78];
    int i = 3;
    puts( "echo~~~~~ech~~~~co~~~ echo 3 times." );
    while( i-- ){
        printf("What do you want to say:");
        read( 0 , s , 0x80 );
        printf( "You said: %s\n" , s );
    }
}


int main(){
    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    puts( "Welcome to NCU center" );

    //char a[0x30] , b[0x30] , c[0x30];
    char s[3][0x10];
    int size = 0x30 , n , i;
    //a[0] = a[1] = a[2] = 0x30;

    while(1){
        menu();
        n = read_int();
        switch( n ){
            case 1:
                echo();
                break;
            case 2:
                printf("Which one do you want to store in (1 , 2 , 3)?:");
                i = read_int();
                if( i < 1 || i > 3 ){
                    puts( "Nop!" );
                    exit(0);
                }
                printf( "What do you want to store in mem page %d :" , i );
                read( 0 , s[i - 1] , 0x30 );
                puts("done!");
                break;
            case 3:
                printf("Which memo page do you want to see (1 , 2 , 3)?:");
                i = read_int();
                if( i < 1 || i > 3 ){
                    puts( "Nop!" );
                    exit(0);
                }
                if( strlen( s[i - 1] ) < 1 ) {
                    puts("There is nothing in this memo page, please store something first.");
                    break;
                }
                printf( "memo page %d : %s" , n , s[i - 1] );
                break;
            case 4:
                printf("Which memo page do you want to edit (1 , 2 , 3)?:");
                i = read_int();
                if( i < 1 || i > 3 ){
                    puts( "Nop!" );
                    exit(0);
                }
                if( strlen( s[i - 1] ) < 1 ) {
                    puts("There is nothing in this memo page, please store something first.");
                    break;
                }
                printf( "Edit memo page %d :" , n  );
                read( 0 , s[i - 1] , size );
                size = strlen( s[i - 1] );
                printf( "done! new size : %d\n" , size );
                break;
            case 5:
                puts("Bye!");
                return 0;
            default:
                puts("Invalid choice!");
                break;
        }
    }


    return 0;
}