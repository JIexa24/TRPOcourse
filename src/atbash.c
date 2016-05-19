#include "atbash.h"
/// perametry- 1:chiper(a) 2:desh

void atbash(char *eng, char *ENG, int desh, FILE ** fout)
{
//  char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
//  char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//                 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25    26    27   
  int i,j,lenght = 1,vvod = 1;
  //int desh = atoi(argv[2]);
 
 *fout = fopen("out.txt","a");
  fprintf(*fout,"Atbash\n\n");
  char *slovo;  
 
  slovo = (char*)malloc( lenght );
 
  lenght = 0;
  
  fprintf(*fout, "Slovo:\n");  
  printf("\nVvedite slovo\n");
 
  while(vvod == 1)
  {
    scanf("%c",&slovo[lenght]);

    if( slovo[lenght] == '\n' ) break;
    slovo = (char*)realloc( slovo, ++lenght+1 );
  }
  for(i = 0; i< lenght;i++)  
    fprintf(*fout, "%c",slovo[i]);

  fprintf(*fout, "\n\n" );
  fprintf(*fout, "rezult:\n");
  for( i = 0; i < lenght; i++ )
  {
  	if( (int)slovo[i] == ' ')
	{
	  fprintf(*fout, " ");
	  continue;
    }
	for( j = 0; j < 28; j++ )
    {
      if( slovo[i] == eng[j] )
      {//poisk v alfavite
        fprintf(*fout,"%c", eng[ 27-j ]);
      }
      if(desh == 0)
	  {
        if( slovo[i] == ENG[j] && j<=25 )
        {
          fprintf(*fout,"%c", ENG[ 25-j ]);
        }
      }
    }    
  }
   
  fprintf(*fout,"\n\n");
  free(slovo);                             
  fclose(*fout);
  system("pause");   
}
