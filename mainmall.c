//#include"ceasar.h"
/*#include<stdio.h>
#include<stdlib.h>*/
#include"ceasar.h"
#include"vizhiner.h"
#include"dvo.h"
#include"atbash.h"
//   char rus[35]={'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', ',' , '.' };
//   char RUS[35]={'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', ',' , '.' };
      
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
    

