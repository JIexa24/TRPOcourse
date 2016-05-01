#include "vizhiner.h"
// perametry- 1:chiper(v) 2:left/right 3:desh

void vizhiner(char *eng, char *ENG, int lorr, int desh)
{
  //char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  //char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
//                 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25    26    27   
  int i,j,o = 1,lenght = 1,klenght = 1,vvod = 1,mas = 1;
  //int lorr = atoi(argv[2]);
  //int desh = atoi(argv[3]);
  
  char *slovo;
 
  slovo = (char*)malloc( lenght );
 
  lenght = 0;
 
  printf("\nVvedite slovo\n");
 
  while(vvod == 1)
  {
    scanf("%c",&slovo[lenght]);

    if( slovo[lenght] == '\n' ) break;
    slovo = (char*)realloc( slovo, ++lenght+1 );
  }                    
    
  char *kodslovo;

  kodslovo = (char*)malloc(klenght);
  klenght = 0; 
  
//  printf("deshifrovka 1-yes/0-no\n");                   
//  scanf("%d%*c",&desh);        
              
  printf("\nVvedite kodslovo\n");
  
  while(vvod == 1)
  {
    scanf("%c",&kodslovo[klenght]);
    if( kodslovo[klenght] == '\n' ) break;
    kodslovo = (char*)realloc( kodslovo, ++klenght+1 ); //tk void
  }
                        
//  printf("\nleft or right?  1-right/0-left?\n");
//  scanf("%d",&lorr);               
   
  int *ceas;
  ceas = (int*)malloc( klenght*sizeof(int) );
  o = 0;
  for( i = 0; i < lenght; i++)
  {
  	if( (int)slovo[i] == ' ' )
	{
	  printf(" ");
	  continue;
    }
    if(o == klenght)
    {
      o = 0;
      mas = 0;
    }
    if (mas == 1)
    {
      for( j = 0; j < 28; j++ )
      {
        if( (kodslovo[o] == eng[j]) || (kodslovo[o] == ENG[j]) )
        {//vizener cheres ceasar
          ceas[o] = j;
          break;               
        } 
      }
    }      
    for( j = 0; j < 28; j++ )
    {                  
      if(slovo[i] == eng[j])
      {//poisk v alfavite
              
        if( lorr ==1 )
        {                
          if( (desh == 0)*( (j+ceas[o]) > 27 )+(desh == 1)*((j-ceas[o]) < 0) )
          {
            printf( "%c",eng[ (desh == 0)*(j+ceas[o]-28)+(desh == 1)*(j-ceas[o]+28) ] );
            break;
          }                                      
          else
          {
            printf("%c",eng[ (desh == 0)*(j+ceas[o])+(desh == 1)*(j-ceas[o]) ]);
            break;
          } //esly vyhodit za ramki+deshifrovka              
        } 
        if( lorr == 0 )
        {                
          if( (desh == 0)*( (j-ceas[o]) < 0 )+(desh == 1)*( (j+ceas[o]) > 27 ) )
          {
            printf( "%c",eng[ (desh == 0)*(j-ceas[o]+28)+(desh == 1)*(j+ceas[o]-28) ] ); 
            break;
          }                               
          else
          {
            printf("%c",eng[ (desh ==0 )*(j-ceas[o])+(desh == 1)*(j+ceas[o]) ]);
            break;
          }
        }                  
      }
                                               
      if( (slovo[i] == ENG[j]) && (j <= 25) )
      {//poisk v alfavite
                
        if( lorr == 1 )
        {                
          if( (desh == 0)*( (j+ceas[o]) > 25 )+(desh == 1)*( (j-ceas[o])<0 ) )
          {
            printf( "%c",ENG[ (desh == 0)*(j+ceas[o]-26)+(desh == 1)*(j-ceas[o]+26) ] );
            break;
          }
          else
          {
            printf("%c",ENG[ (desh == 0)*(j+ceas[o])+(desh == 1)*(j-ceas[o]) ]);
            break;
          } //esly vyhodit za ramki+deshifrovka              
        } 
    
        if( lorr == 0 )
        {                
          if( (desh == 0)*( (j-ceas[o]) < 0 )+(desh == 1)*( (j+ceas[o]) > 25 ) )
          {
            printf( "%c",ENG[ (desh == 0)*(j-ceas[o]+26)+(desh == 1)*(j+ceas[o]-26) ] ); 
            break;
          }                               
          else
          {
          printf("%c",ENG[ (desh == 0)*(j-ceas[o])+(desh == 1)*(j+ceas[o]) ]);
          break;
          }
        }                  
      }                       
    }               
  
    o++;            
  
    if(i == lenght)break;   
 
  }
  
  printf("\n");
  
  free(slovo);
  free(kodslovo);
  free(ceas);
                    
  system("pause");
}  
