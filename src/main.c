#include "../include/atbash.h"
#include "../include/base64.h"
#include "../include/ceasar.h"
#include "../include/vizhiner.h"

#include <unistd.h>

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

#define FALSE 0
#define TRUE 1

const char *eng = "abcdefghijklmnopqrstuvwxyz";
const char *sym = ",.";
const char *ENG = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(int argc, char *argv[]) {
  char *a = NULL;
  FILE *fout = NULL;
  int opt;
  int variant = 0, key = -1, vector = 1, decode = 1;
  char *word = NULL;
  char *keyword = NULL;
  printf("Chipers\n");
  printf("1.Chiper ceasar\n");
  printf("2.Chiper Vizhiner\n");
  printf("3.Chiper Atbash\n");
  printf("4.Chiper Base64\n\n");

  opterr = 0;

  while ((opt = getopt(argc, argv, "cvabk:ldw:o:")) != -1) {
    switch (opt) {
    case 'c':
      if (variant == 0)
        variant = 1;
      break;

    case 'k':
      if (variant == 1) {
        key = atoi(optarg);
      } else {
        keyword = optarg;
      }
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
      vector = -1;
      break;

    case 'd':
      decode = -1;
      break;

    case 'w':
      word = optarg;
      break;

    case 'o':
      fout = fopen(optarg, "a");
      break;
    }
  }

  if (variant == 0) {
    printf("Enter variant (1-4) :");
    scanf("%d%*c", &variant);
    printf("\n");
  }

  switch (variant) {
  case ONE:
    a = ceasar(key, vector, decode, TRUE, word, fout);
    free(a);
    break;

  case TWO:
    a = vizhiner(keyword, vector, decode, TRUE, word, fout);
    free(a);
    break;

  case THREE:
    a = atbash(TRUE, word, fout);
    free(a);
    break;

  case FOUR:
//    a = BASE64(debug, fout, &word);
//    free(a);
    break;

  default:
    printf("Miss chiper\n");
    break;
  }

  return 0;
}
