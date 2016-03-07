//#include"ceasar.h"
/*#include<stdio.h>
#include<stdlib.h>*/
#include"ceasar.h"
#include"vizhiner.h"
#include"dvo.h"
#include"atbash.h"
//   char rus[35]={'à','á','â','ã','ä','å','¸','æ','ç','è','é','ê','ë','ì','í','î','ï','ð','ñ','ò','ó','ô','õ','ö','÷','ø','ù','ú','û','ü','ý','þ','ÿ', ',' , '.' };
//   char RUS[35]={'À','Á','Â','Ã','Ä','Å','¨','Æ','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï','Ð','Ñ','Ò','Ó','Ô','Õ','Ö','×','Ø','Ù','Ú','Û','Ü','Ý','Þ','ß', ',' , '.' };
      
int main()
{ 
  int variant;
 
  printf("Chipers\n");

  printf("1.Chiper ceasar\n");

  printf("2.Chiper Vizhiner\n");
 
  printf("3.Chiper EGE\n");
  
  printf("4.Chiper Atbash\n");
   
  scanf("%d%*c",&variant);  
  
  switch(variant)
  {  
    case 1:ceasar();break;
    case 2:vizhiner();break;
    case 3:dvo();break;
    case 4:atbash();break;
    default:break;
  }
  return 0;
  
}
    

