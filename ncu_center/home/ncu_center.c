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

void echo(){
    char s[0x70];
    printf("What do you want to say:");
    read( 0 , s , 0x70 );
    printf( "You said: %s\n" , s );
}


int main(){
    setvbuf(stdout,0,2,0);
    puts( "Welcome to NCU center" );

    //char a[0x30] , b[0x30] , c[0x30];
    char s[3][0x30];
    int a[3] , n;
    a[0] = a[1] = a[2] = 0x30;

    while(1){
        menu();
        scanf( "%d" , &n );
        switch( n ){
            case 1:
                echo();
                break;
            case 2:
                printf("Which one do you want to store in (1 , 2 , 3)?:");
                scanf( "%d" , n );
                printf( "What do you want to store in mem page %d :" , n );
                read( 0 , s[n] , 0x30 );
                puts("done!");
                break;
            case 3:
                printf("Which memo page do you want to see (1 , 2 , 3)?:");
                scanf( "%d" , n );
                if( strlen( s[n] ) < 1 ) {
                    puts("There is nothing in this memo page, please store something first.");
                    break;
                }
                printf( "memo page %d : %s" , n , s[n] );
                break;
            case 4:
                printf("Which memo page do you want to edit (1 , 2 , 3)?:");
                scanf( "%d" , n );
                if( strlen( s[n] ) < 1 ) {
                    puts("There is nothing in this memo page, please store something first.");
                    break;
                }
                printf( "Edit memo page %d :" , n  );
                read( 0 , s[n] , a[n] );
                a[n] = strlen( s[n] );
                printf( "done! new size : %d\n" , a[n] );
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