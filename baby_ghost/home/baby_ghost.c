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
    puts("        ;   /^\\   ;");
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
    puts( "4. show" );
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

int main(){
    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    puts( "Woooooo~~~ Where is the ghost.........." );

    

    while(1){
        skull();
        menu();
        n = read_int();
        switch( n ){
            case 1:

                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
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