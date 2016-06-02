#include "../include/ceasar.h"
#include "../include/vizhiner.h"
#include "../include/atbash.h"
#include "../include/base64.h"

#include <unistd.h>

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

int main(int argc, char * argv[])
{
  const char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  const char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

  FILE * fout;

  printf("Chipers\n");
  printf("1.Chiper ceasar\n");
  printf("2.Chiper Vizhiner\n");
  printf("3.Chiper Atbash\n");
  printf("4.Chiper Base64\n\n");

  int opt;
  int variant = 0, kluch = -1, lorr = 1, debug = 0;

  opterr = 0;
  while ((opt = getopt(argc, argv, "cvabk:ld")) != -1) {
    switch (opt) {
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
      
      case 'b':
        if (variant == 0)
          variant = 4;
      break;

      case 'l':
        lorr = 0;
      break;

      case 'd':
        debug = 1;
      break;
    }
  }

  if (kluch < 0 && variant == 1) {
    printf("\nmiss key for ceasar\n");
    return 1;
  }

  switch (variant) {
    case ONE:
      ceasar(eng, ENG, kluch, lorr, debug, &fout);
    break;

    case TWO:
      vizhiner(eng, ENG, lorr, debug, &fout);
    break;

    case THREE:
      atbash(eng, ENG, debug, &fout);
    break;
    
    case FOUR:
      BASE64();
    break;

    default:
      printf("Miss chiper\n");
    break;
  }

  return 0;
}
