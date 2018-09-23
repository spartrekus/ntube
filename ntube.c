

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


void mytubeplayer( char *myurl, char *myapp )
{

    ////////////////////////////////////////////////////////
    char cwd[PATH_MAX];
    char cmdi[PATH_MAX];
    strncpy( cwd, "" , PATH_MAX );
    char pathbefore[PATH_MAX];
    strncpy( pathbefore , getcwd( cwd, PATH_MAX ) , PATH_MAX );
    printf( "PATH: %s\n" , pathbefore  );
    FILE *fp;

        chdir( pathbefore );
        chdir( getenv( "HOME" ) );
        fp = fopen( ".ntube.ini" , "ab+" );
          fputs( myurl , fp );
          fputs( "\n" , fp );
        fclose( fp );
        chdir( pathbefore );

         printf( "PATH: %s\n", getenv( "HOME" ) );
         strncpy( cmdi, "", PATH_MAX );
         strncat( cmdi , "       " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , myapp , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "     " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "   $( python   ~/.youtube-dl -g  " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  " \""  , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , myurl , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  "\" "  , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  " ) "  , PATH_MAX - strlen( cmdi ) -1 );
         printf( "<CMD: %s>\n", cmdi );
         system( cmdi );
    }


int main( int argc, char *argv[])
{
    ////////////////////////////////////////////////////////
    printf("Hello TUBE Service \n");
    char ipbegin[PATH_MAX];
    FILE *fp;

    ////////////////////////////////////////////////////////
    char cwd[PATH_MAX];
    char cmdi[PATH_MAX];
    strncpy( cwd, "" , PATH_MAX );
    char pathbefore[PATH_MAX];
    strncpy( pathbefore , getcwd( cwd, PATH_MAX ) , PATH_MAX );
    printf( "PATH: %s\n" , pathbefore  );


    ////////////////////
    if ( argc == 2)
     if ( ( strcmp( argv[1] , "--install" ) ==  0 ) 
     || ( strcmp( argv[1] , "--wget" ) ==  0 ) 
     || ( strcmp( argv[1] , "--install" ) ==  0 ) )
     {
        printf("TUBE Service: wget / Install...\n");
        system( " cd ; wget \"https://yt-dl.org/downloads/2017.08.23/youtube-dl\" -O ~/.youtube-dl  " );
        return 0;
     }

     if ( argc == 2)
     if  ( strcmp( argv[1] , "upgrade" ) ==  0 ) 
     {
        system( "  cd ; python ~/.youtube-dl -U  " );
        return 0;
     }


    ////////////////////////////////
    if ( argc == 2)
     if ( ( strcmp( argv[1] , "install" ) ==  0 ) 
     || ( strcmp( argv[1] , "install" ) ==  0 ) )
     {
        printf("TUBE Service: Curl / Install...\n");
        //system( " cd ; curl -L \"https://yt-dl.org/downloads/2017.08.23/youtube-dl\" -o ~/.youtube-dl  " );
        system( " cd ; wget \"https://yt-dl.org/downloads/2017.08.23/youtube-dl\" -O ~/.youtube-dl  " );
        system( " cd ; python ~/.youtube-dl -U  " );
        return 0;
     }




    if ( argc == 2)
     if ( ( strcmp( argv[1] , "help" ) ==  0 ) 
     || ( strcmp( argv[1] , "--help" ) ==  0 ) )
     {
        system( " python   ~/.youtube-dl  --help  " );
        return 0;
     }


     if ( ( strcmp( argv[1] , "chip" ) ==  0 ) 
     || ( strcmp( argv[1] , "--chip" ) ==  0 ) )
     {
        system( " python   ~/.youtube-dl  \"https://www.youtube.com/watch?v=1-x1kz3OHvw\"   " );
        return 0;
     }


     ////////////////////////////////////////////
     if ( argc == 3)
     if ( strcmp( argv[1] , "play" ) ==  0 ) 
     if ( strcmp( argv[2] , "xclip" ) ==  0 ) 
     {
        mytubeplayer( "$( xclip -o )" , " mplayer -ao null -zoom " );
        return 0;
     }



     if ( ( strcmp( argv[1] , "play" ) ==  0 ) 
     || ( strcmp( argv[1] , "--mp" ) ==  0 ) 
     || ( strcmp( argv[1] , "--play" ) ==  0 ) )
     {
        //system( "  python ~/.youtube-dl ` xclip -o `  --exec \"  mplayer -fs \"      " );
        //mytubeplayer( argv[ 2 ] , " nmplayer " );
        mytubeplayer( argv[ 2 ] , " mplayer -ao null -zoom " );
        return 0;
     }





     if  ( strcmp( argv[1] , "--mpg" ) ==  0 ) 
     {
        mytubeplayer( argv[ 2 ] , " mpg123 " );
        return 0;
     }


    if ( argc == 2)
     if ( ( strcmp( argv[1] , "save" ) ==  0 ) 
     || ( strcmp( argv[1] , "--save" ) ==  0 ) )
     {
        printf( "  cd ; xclip -o >> .ntubes.ini ; echo >> .ntubes.ini \n" );
        system( "  cd ; xclip -o >> .ntubes.ini ; echo >> .ntubes.ini "  );
        return 0;
     }





    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    if ( argc == 2)
     if ( ( strcmp( argv[1] , "xclip" ) ==  0 ) 
     || ( strcmp( argv[1] , "--xclip" ) ==  0 ) )
     {
        ////////////////////////////////////////////////////////
        chdir( pathbefore );
        FILE *fp;
        chdir( getenv( "HOME" ) );
        //fp = fopen( ".ntube.ini" , "ab+" );
        //fputs( "\n", fp ); 
        //fclose( fp );
        system( " xclip -o >> .ntube.ini " );
        fp = fopen( ".ntube.ini" , "ab+" );
        fputs( "\n", fp ); 
        fclose( fp );
        chdir( pathbefore );

         printf("\n");
         printf("TUBE: %s ...\n", argv[ 1 ] );
         system( " xclip -o  " );
         printf("\n");
         strncpy( cmdi, "", PATH_MAX );
         strncat( cmdi , " python   ~/.youtube-dl  " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  "  \""  , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "$( xclip -o )" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  "\" "  , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
         printf( "<CMD: %s>\n", cmdi );
         system( cmdi );
         return 0;
     }





    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    {
        chdir( pathbefore );
        chdir( getenv( "HOME" ) );
        fp = fopen( ".ntube.ini" , "ab+" );
          fputs( argv[ 1 ] , fp );
          fputs( "\n" , fp );
        fclose( fp );
        chdir( pathbefore );

         printf( "PATH: %s\n", getenv( "HOME" ) );
         printf("TUBE: %s ...\n", argv[ 1 ] );
         strncpy( cmdi, "", PATH_MAX );
         strncat( cmdi , " python   ~/.youtube-dl  " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  "  \""  , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , argv[1] , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi ,  "\" "  , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
         printf( "<CMD: %s>\n", cmdi );
         system( cmdi );
         return 0;
    }


    //if ( argc == 2)
    {
       printf( " python -g  ~/.youtube-dl url to get the download link\n" );
    }

    return 0;
}



