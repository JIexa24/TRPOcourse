#include"ceasar.h"
#include"vizhiner.h"
#include"dvo.h"
#include"atbash.h"
//   char rus[35]={'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', ',' , '.' };
//   char RUS[35]={'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', ',' , '.' };
       
int main(int argc, char * argv[])
{  // char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  //char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
  
  printf("Chipers\n");

  printf("1.Chiper ceasar\n");

  printf("2.Chiper Vizhiner\n");
 
  printf("3.Chiper EGE\n");
  
  printf("4.Chiper Atbash\n");
   
  //scanf("%d%*c",&variant);  
  int variant = atoi(argv[1]);
  
  switch(variant)
  {  
    case 1:ceasar(argv);break;
    case 2:vizhiner(argv);break;
    case 3:dvo(argv);break;
    case 4:atbash(argv);break;
    default:break;
  }
  return 0;
  
}
    

