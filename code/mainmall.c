#include "ceasar.h"
#include "vizhiner.h"
#include "atbash.h"

#include <unistd.h>

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

//   char rus[35]={'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я', ',' , '.' };
//   char RUS[35]={'А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я', ',' , '.' };
       
int main(int argc, char * argv[])
{
  char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
  
  printf("Chipers\n");

  printf("1.Chiper ceasar\n");

  printf("2.Chiper Vizhiner\n");
 
  //printf("3.Chiper EGE\n");
  
  printf("3.Chiper Atbash\n");
  int opt;
  int variant = 0, kluch = -1, lorr = 1, debug = 0;
	//opterr = 0; // запретить вывод ошибок от getopt()
	while ((opt = getopt(argc, argv, "cvak:ld")) != -1)
	{
		switch (opt)
		{
			case 'c':
			  if (variant == 0)
				variant = 1;	
			break;
			case 'k':
				kluch = atoi(optarg);
			break;
			case 'v':
			  if (variant == 0)
				variant = 2;
			break;
      case 'a':
        if (variant == 0)
				  variant = 3;
      break;
			case 'l':
				lorr = 0;
			break;
			case 'd':
				debug = 1;
			break;
		}
	} 
  //scanf("%d%*c",&variant);  
  //int variant = atoi(argv[1]);
  if (kluch < 0 && variant == 1)
  {
  	printf("\nmiss key for ceasar");
    return 1;
	}
    
  //printf("%d", variant);
  switch(variant)
  {  
    case ONE: ceasar(eng, ENG, kluch, lorr, debug); break;
    case TWO: vizhiner(eng, ENG, lorr, debug); break;
    case THREE: atbash(eng, ENG, debug); break;
    default: printf("error");break;
  }
  return 0;
  
}
    

