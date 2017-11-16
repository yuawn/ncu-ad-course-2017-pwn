#include<stdio.h>
#include<stdlib.h>


/*
	
 _;~)                  (~;_
(   |                  |   )
 ~', ',    ,''~'',   ,' ,'~
     ', ','       ',' ,'
       ',: {'} {'} :,'
         ;   /^\   ;
          ~\  ~  /~
        ,' ,~~~~~, ',
      ,' ,' ;~~~; ', ',
    ,' ,'    '''    ', ',
  (~  ;               ;  ~)
   -;_)               (_;-
*/

void skull(){
    puts(" _;~)                  (~;_");
    puts("(   |                  |   )");
    puts(" ~', ',    ,''~'',   ,' ,'~");
    puts("     ', ','       ',' ,'");
    puts("       ',: {'} {'} :,'");
    puts("         ;   /^\\   ;");
    puts("          ~\\  ~  /~");
    puts("        ,' ,~~~~~, ',");
    puts("      ,' ,' ;~~~; ', ',");
    puts("    ,' ,'    '''    ', ',");
    puts("  (~  ;               ;  ~)");
    puts("   -;_)               (_;-");
}

void menu(){
    puts( "---------------------------" );
    puts( "1. add a human" );
    puts( "2. modify a human" );
    puts( "3. add a ghost" );
    puts( "4. modify a ghost" );
    puts( "5. show" );
    puts( "6. exit" );
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

struct human{
    char dsc[0x100];
    char *name;
};

struct ghost{
    char dsc[0x18];
    char *name;
};

struct human *h[10];
struct ghost *g;

void add_human(){

    char buf[0x20];
    memset( buf , 0 , 0x20 );

    for( int i = 0 ; i < 10 ; ++i ){
        if( !h[i] ){
            h[i] = malloc( sizeof(struct human) );
            memset( h[i]->dsc , 0 , 0x10 );
            printf( "Say something :" );
            read( 0 , h[i]->dsc , 0xff );
            printf( "Oh! Your name :" );
            int len = read( 0 , buf , 0x1f );
            if( buf[len - 1] = '\n' ) buf[len - 1] = '\x00';
            h[i]->name = strdup( buf );
            puts( "done!" );
            return;
        }
    }
    puts( "Full!" );
    return;
}

void add_ghost(){
    if( !g ){
        g = malloc( sizeof( struct ghost ) );
        memset( g->dsc , 0 , 0x10 );
        printf( "What does the ghost say :" );
        read( 0 , g->dsc , 0x10 );
        printf( "ghost name size :" );
        int size = read_int();
        char *tmp = NULL;
        tmp = malloc( size );
        if( !tmp ){
            puts( "Alloc error" );
            return;
        }
        g->name = tmp;
        printf( "ghost name :" );
        read( 0 , g->name , size );
        puts( "You let me free, it must has some blood this night." );
        return;
    }
    puts( "There is already a ghost!!!!! RUN!!!!!" );
    exit(0);
}

void mod_human(){
    char buf[0x20];
    printf( "Index:" );
    unsigned int i = read_int() ;
    if( i > 9 ){
        puts( "Nop!" );
        exit(0);
    }
    if( !h[i] ){
        puts( "There is nobody." );
        return;
    }
    printf( "New name:" );
    read( 0 , buf, 0x1f );
    h[i]->name = realloc( h[i]->name , strlen( buf ) );
    strncpy( h[i]->name , buf , strlen( buf ) );
    puts( "done!" );
    return;
}

void mod_ghost(){
    if( !g ){
        puts( "Wooooooooo~~~ miss me?" );
        return;
    }
    else if( g == 0x9487 ){
        puts( "I got you WA HA HA." );
        exit(0);
    }
    printf( "New name of ghost :" );
    read( 0 , g->name , 2 );
    g = 0x9487;
    puts( "OH NO!! Im cursed......" );
    return;
}

void show(){
    for( int i = 0 ; i < 10 ; ++i ){
        if( h[i] ){
            printf( "%s: %s\n", h[i]->name , h[i]->dsc  );
        }
    }
    puts( "You can't see the ghost, find it!" );
    return;
}

int main(){
    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    skull();
    puts( "Woooooo~~~ Where is the ghost.........." );

    int n;

    while(1){
        menu();
        n = read_int();
        switch( n ){
            case 1:
                add_human();
                break;
            case 2:
                mod_human();
                break;
            case 3:
                add_ghost();
                break;
            case 4:
                mod_ghost();
                break;
            case 5:
                show();
                break;
            case 6:
                puts("Bye!");
                return 0;
            default:
                puts("Invalid choice!");
                break;
        }
    }


    return 0;
}