
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <time.h>


int foundcmd = 0;


void runwith( char *thecmd , char *thefile )
{
       char cmdi[PATH_MAX];
       printf( "<CMD: %s>\n" , thecmd ) ; 
       printf( "<FILE: %s>\n" , thefile ) ; 
       strncpy( cmdi , "  " , PATH_MAX );
       strncat( cmdi , thecmd , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , " \"" , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , thefile , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , "\"" , PATH_MAX - strlen( cmdi ) -1 );
       system( cmdi );
}





char *strcut( char *str , int myposstart, int myposend )
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( ( str[i] != '\0' ) && ( str[i] != '\0') )
         if ( ( i >=  myposstart-1 ) && (  i <= myposend-1 ) )
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}




char *strtrim(char *str)
{  
      // right side to to finish
      char ptr[strlen(str)+1];
      int strposmax = strlen( str );
      int lastposchar = strposmax;
      int i,j=0;
      int foundspace = 1;

      /// find last char
      foundspace = 1;
      for( i= strposmax-1 ; i >= 0 ; i--)
      {
         //printf( "|%d-%d-%c| ", i , lastposchar , str[i] );
	 // find where to space
         if ( foundspace == 1 ) 
         if ( str[i] == ' ' ) 
   	    lastposchar = i-1;

         if ( str[i] != ' ' ) 
           foundspace = 0;
      } 

      // add the content
      foundspace = 1;
      for(i=0; i <= lastposchar ; i++)
      {
        if ( foundspace == 1 ) 
         if ( ( str[i] != ' ' )  && ( str[i] != 9 ) ) //added! with 9 for a TAB!!
          foundspace = 0;

        if ( foundspace == 0 ) 
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';

      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}





///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void filecat(  char *filein )
{
  int fetchi;
  FILE *fp5;
  FILE *fp6;
  char fetchline[PATH_MAX];
  char fetchlinetmp[PATH_MAX];
  char inputfield[PATH_MAX];

  int linecounter = 1;

  /////////////////////////////////////////////////
  {

    printf( "\n" );
    printf( "###################################\n" );
    printf( "!title %s\n", filein );
    printf( "###################################\n" );

    //fp5 = fopen( fileout , "ab+");
    fp6 = fopen( filein , "rb");
    while( !feof(fp6) ) 
    {
          fgets(fetchlinetmp, PATH_MAX, fp6); 
          strncpy( fetchline, "" , PATH_MAX );
          for( fetchi = 0 ; ( fetchi <= strlen( fetchlinetmp ) ); fetchi++ )
            if ( fetchlinetmp[ fetchi ] != '\n' )
              fetchline[fetchi]=fetchlinetmp[fetchi];

         if ( !feof(fp6) )
         {
	      printf( "%d: %s", linecounter++, fetchline );
	      printf( "\n" );
              foundcmd = 0;


              ///////////////////////////////////
              if ( foundcmd == 0 )
              if ( fetchline[0] == '#' )
              {
	         //printf( "# Skip \n" );
                  foundcmd = 1;
              }
              ///////////////////////////////////
              if ( foundcmd == 0 )
              if ( fetchline[0] == '/' )
              if ( fetchline[1] == '/' )
              {
	          //printf( "# Skip \n" );
                  foundcmd = 1;
              }


              /////////////////////////
              // !mplayer 
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'm' )
              if ( fetchline[2] == 'p' )
              if ( fetchline[3] == 'l' )
              if ( fetchline[4] == 'a' )
              if ( fetchline[5] == 'y' )
              if ( fetchline[6] == 'e' )
              if ( fetchline[7] == 'r' )
              if ( fetchline[8] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!mplayer (!mp)\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 3+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 //runwith( " nmplayer " , inputfield );                 
                 runwith( " mplayer " , inputfield );                 
                 foundcmd = 1;
              }



              /////////////////////////
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'n' )
              if ( fetchline[2] == 'm' )
              if ( fetchline[3] == 'p' )
              if ( fetchline[4] == 'l' )
              if ( fetchline[5] == 'a' )
              if ( fetchline[6] == 'y' )
              if ( fetchline[7] == 'e' )
              if ( fetchline[8] == 'r' )
              if ( fetchline[9] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!nmplayer (!mp)\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 8+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " nmplayer " , inputfield );                 
                 foundcmd = 1;
              }





              // !ntube 
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'n' )
              if ( fetchline[2] == 't' )
              if ( fetchline[3] == 'u' )
              if ( fetchline[4] == 'b' )
              if ( fetchline[5] == 'e' )
              if ( fetchline[6] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!NTUBE\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 6+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " ntube  " , inputfield );                 
                 foundcmd = 1;
              }

              // !ntubemp 
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'n' )
              if ( fetchline[2] == 't' )
              if ( fetchline[3] == 'u' )
              if ( fetchline[4] == 'b' )
              if ( fetchline[5] == 'e' )
              if ( fetchline[6] == 'm' )
              if ( fetchline[7] == 'p' )
              if ( fetchline[8] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!NTUBE MPLAYER\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 8+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " ntube play " , inputfield );                 
                 foundcmd = 1;
              }
        /*
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
        */





              // !fig (...)
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'f' )
              if ( fetchline[2] == 'i' )
              if ( fetchline[3] == 'g' )
              if ( fetchline[4] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!FIG\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 4+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " feh -FZ  " , inputfield );                 
                 foundcmd = 1;
              }

              // !cr (...)  for chromium-browser (Pi)
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'c' )
              if ( fetchline[2] == 'r' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!URL (chromium)\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 3+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " chromium-browser " , inputfield );                 
                 foundcmd = 1;
              }


              // !url (...)
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'u' )
              if ( fetchline[2] == 'r' )
              if ( fetchline[3] == 'l' )
              if ( fetchline[4] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!URL\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 4+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " chromium-browser " , inputfield );                 
                 foundcmd = 1;
              }


              // !runurl (...)
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'r' )
              if ( fetchline[2] == 'u' )
              if ( fetchline[3] == 'n' )
              if ( fetchline[4] == 'u' )
              if ( fetchline[5] == 'r' )
              if ( fetchline[6] == 'l' )
              if ( fetchline[7] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!URL\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 7+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " chromium-browser " , inputfield );                 
                 foundcmd = 1;
              }
              // !urlrun   (outdated)
              if ( fetchline[0] == '!' )
              if ( fetchline[1] == 'u' )
              if ( fetchline[2] == 'r' )
              if ( fetchline[3] == 'l' )
              if ( fetchline[4] == 'r' )
              if ( fetchline[5] == 'u' )
              if ( fetchline[6] == 'n' )
              if ( fetchline[7] == ' ' )
              if ( foundcmd == 0 )
              {
	         printf( "!URL\n" );
                 strncpy( inputfield, strtrim( strcut( fetchline, 7+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "[%s]\n", inputfield );
                 runwith( " chromium-browser " , inputfield );                 
                 foundcmd = 1;
              }





	 } // end of check end of file
     }
     fclose( fp6 );
   }
}





int main( int argc, char *argv[])
{
    char cwd[PATH_MAX]; int i ; 

    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    if ( strcmp(argv[1], "--arg" ) == 0)
    {
          for( i = 1 ; i < argc ; i++) 
	     printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i] );
          return 0;
    }
    
    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    {
          for( i = 1 ; i < argc ; i++) 
	     filecat( argv[ i ] );
          return 0;
    }

    return 0;
}


