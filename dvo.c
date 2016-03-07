#include"dvo.h"
void per( int chislo )
{
  int del = 2,k = 0,i,ost;
  int chislo1 = chislo;  
               
  while(del >= 1) /*del-потому что если ввести 0,то ничего не выведет.*/
  {        
    del = chislo/2;        
    chislo = del;
    k++;
  }  
  int * a;
  a = (int*)malloc( k*sizeof(int) );
  
  for( i = 0; i < k; i++ )
  {
    ost = chislo1-(chislo1/2)*2;
    a[i] = ost;
    chislo1 /= 2;       
  }  
  for( i = k-1; i >= 0; i-- )
  {
    printf("%d",a[i]);
  }
                     
}

void dvo()
{
  char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
//                 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25    26    27   
  int ceas,i,j=0,lenght = 1,desh = 0,lorr,vvod = 1;    
  char *slovo;
  
  slovo = (char*)malloc( lenght );   
     
  lenght = 0; 
  printf("deshifrovka 1-yes/0-no");                         
  scanf("%d%*c",&desh);  
  printf("\nVvedite slovo\n");
 
 

  while( vvod == 1 )
  {
    scanf("%c",&slovo[lenght]);
    
    if( slovo[lenght] == '\n' )break;//zakonchit vvod 
    
    slovo = (char*)realloc( slovo, ++lenght+1 );
  }
  
    printf("\n");
  
  if( desh == 0 )
  {  
    for( i = 0; i < lenght; i++)
    {
  	if(  slovo[i] == ' '  )
	{
	  printf(" ");
	  continue;
    }
      for(j=0;j<28;j++)
      {
        if(slovo[i] == eng[j] || ( j<=25 )*(slovo[i] == ENG[j]) )
        {                
          if(j < 16)
          {
            printf("0");        
          }
          if(j < 8)
          {
            printf("0");        
          }
          if(j < 4)
          {
            printf("0");        
          }
          if(j < 2)
          {
            printf("0");        
          }
          per(j);
          printf(" ");                  
        }     
      }                     
    }
  }
  if( desh == 1 )
  {
    int step=32;  
    for( i = 0; i < lenght; i++)
    {
      if( slovo[i] == '1')j = j+step;
      step/=2;
      if( (i+1)%6 == 0 )
      {
        printf("%c",eng[j]);
        step = 32;
        j = 0;
      }     
    }          
  }
  printf("\n");
 
  free(slovo);                             

  system("pause");
              }
