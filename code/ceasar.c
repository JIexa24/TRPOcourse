#include "ceasar.h"
// perametry- 1:chiper(c) 2:kluch 3:left/right 4:desh

void ceasar(char *eng, char *ENG, int ceas, int lorr, int desh, FILE ** fout)
{//ceasar chiper
  //char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  //char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
//                 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25    26    27   
  int i,j,lenght = 1,vvod = 1;    
 // int ceas = atoi(argv[2]);
  //int lorr = atoi(argv[3]);
 // int desh = atoi(argv[4]);
  printf("%d", ceas);
  *fout = fopen("out.txt","a");

  char *slovo;

  slovo = (char*)malloc( lenght );   
     
  lenght = 0; 
  fprintf(*fout, "Ceasar\n");
  fprintf(*fout, "\nSlovo:\n");
  printf("\nVvedite slovo\n");
  
  while( vvod == 1 )
  {
    scanf("%c",&slovo[lenght]);
    
    if( slovo[lenght] == '\n' )break;//zakonchit vvod 
    
    slovo = (char*)realloc( slovo, ++lenght+1 );
  }
     
  /*printf("deshifrovka 1-yes/0-no");                         
  scanf("%d",&desh);         
             
  printf("\nVvod cdviga\n");
  scanf("%d",&ceas);
  
  printf("\nleft or right?  1-right/0-left?\n");
  scanf("%d",&lorr);*/
  for(i = 0; i< lenght;i++)  
    fprintf(*fout, "%c",slovo[i]);

  fprintf(*fout, "\n\nkluch:%d\n\n", ceas );
  fprintf(*fout, "rezult:\n");
  for( i = 0; i < lenght; i++ )
  {
  	if( (int)slovo[i] == ' ' )
	{
	  fprintf(*fout," ");
	  continue;
    }
    for( j = 0; j < 28; j++ )
    {
      if( slovo[i] == eng[j] )
      {//poisk v alfavite
        if( ceas > 28 )
        {
          for( ceas; ceas > 28; ceas = ceas-28 ); //esli sdvig bolshe chem bukv v alfavite
        }
        if( lorr == 1 )
        {                
          if( ( desh == 0 )*( (j+ceas) > 27 ) + ( desh == 1 )*( (j-ceas) < 0 ) )
          {
            fprintf(*fout, "%c", eng[ (desh == 0)*(j+ceas-28)+(desh == 1)*(j-ceas+28) ] ); 
          }                               
          else
          { 
            fprintf(*fout, "%c",eng[ (desh == 0)*(j+ceas)+(desh == 1)*(j-ceas) ]); //esly vyhodit za ramki+deshifrovka              
          }
        } 
        if( lorr == 0 )
        {                
          if( (desh == 0)*( (j-ceas) < 0 )+(desh == 1)*( (j+ceas) > 27 ) )
          {
            fprintf(*fout, "%c",eng[ (desh == 0)*(j-ceas+28)+(desh == 1)*(j+ceas-28) ] ); 
          }                                
          else
          { 
            fprintf(*fout, "%c",eng[ (desh == 0)*(j-ceas)+(desh == 1)*(j+ceas) ]);
          }
        }                  
      }                 
      
      if(slovo[i]==ENG[j] && j <= 25)
      {
        if(ceas>25)
        {
          for(ceas;ceas>25;ceas=ceas-25);
        }
        if( lorr==1 )
        {                
          if( (desh==0)*((j+ceas)>25)+(desh==1)*((j-ceas)<0) )
            fprintf(*fout, "%c",ENG[ (desh==0)*(j+ceas-26)+(desh==1)*(j-ceas+26) ]);                               
          else 
            fprintf(*fout, "%c",ENG[ (desh==0)*(j+ceas)+(desh==1)*(j-ceas) ]);               
        } 
        if( lorr==0 )
        {                
          if( (desh==0)*((j-ceas)<0)+(desh==1)*((j+ceas)>25) )
             fprintf(*fout,"%c",ENG[ (desh==0)*(j-ceas+26)+(desh==1)*(j+ceas-26) ]);                                
          else 
             fprintf(*fout,"%c",ENG[ (desh==0)*(j-ceas)+(desh==1)*(j+ceas) ]);
        }                  
      }                 
    }
//              –¿«Œ¡–¿“‹—ﬂ!                          
/*        for(j=0;j<35;j++){
         if(slovo[i]==rus[j]){//poisk v alfavite
            if(ceas>35){
             for(ceas;ceas>35;ceas=ceas-35); //esli sdvig bolshe chem bukv v alfavite
                        }
         if( lorr==1 ){                
            if( (desh==0)*((j+ceas)>34)+(desh==1)*((j-ceas)<0) )printf( "%c",rus[ (desh==0)*(j+ceas-35)+(desh==1)*(j-ceas+35) ] );                                
             else printf("%c",rus[ (desh==0)*(j+ceas)+(desh==1)*(j-ceas) ]); //esly vyhodit za ramki+deshifrovka              
                      } 
         if( lorr==0 ){                
            if( (desh==0)*((j-ceas)<0)+(desh==1)*((j+ceas)>34) )printf( "%c",rus[ (desh==0)*(j-ceas+35)+(desh==1)*(j+ceas-35) ] );                                
             else printf("%c",rus[ (desh==0)*(j-ceas)+(desh==1)*(j+ceas) ]);
                        }                  
                              }                 
                          }
                          
        for(j=0;j<35;j++){
         if(slovo[i]==RUS[j]){//poisk v alfavite
            if(ceas>35){
             for(ceas;ceas>35;ceas=ceas-35); //esli sdvig bolshe chem bukv v alfavite
                        }
         if( lorr==1 ){                
            if( (desh==0)*((j+ceas)>34)+(desh==1)*((j-ceas)<0) )printf( "%c",RUS[ (desh==0)*(j+ceas-35)+(desh==1)*(j-ceas+35) ] );                                
             else printf("%c",RUS[ (desh==0)*(j+ceas)+(desh==1)*(j-ceas) ]); //esly vyhodit za ramki+deshifrovka              
                      } 
         if( lorr==0 ){                
            if( (desh==0)*((j-ceas)<0)+(desh==1)*((j+ceas)>34) )printf( "%c",RUS[ (desh==0)*(j-ceas+35)+(desh==1)*(j+ceas-35) ] );                                
             else printf("%c",RUS[ (desh==0)*(j-ceas)+(desh==1)*(j+ceas) ]);
                        }                  
                              }                 
                          }*/
                          
  }              
 
  fprintf(*fout, "\n\n");
 
  free(slovo);                             
  fclose(*fout);
  system("pause");
}
