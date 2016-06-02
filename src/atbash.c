#include "../include/atbash.h"

void atbash(const char *eng, const char *ENG,
            int desh, FILE * fout, char ** word)
{
  int i,j,lenght = 0,vvod = 1;

  if (*word == NULL) {
    *word = (char*)malloc(sizeof(word));

    printf("\nOriginal word :");

    while (vvod) {
      scanf("%c", &(*word)[lenght]);

      if ((*word)[lenght] == '\n') {
        (*word)[lenght] = '\0';
        break;
      }

      *word = (char*)realloc(*word, ++lenght+1);
    }
  }
  else {
    lenght = strlen(*word);
  }

  char *codeword = (char *)malloc(lenght * sizeof(char *));

  for (i = 0; i < lenght; i++) {
    if ((*word)[i] == ' ') {
        codeword[i] = ' ';
      continue;
    }

    for (j = 0; j < 28; j++) {
      if ((*word)[i] == eng[j]) {
        codeword[i] = eng[27 - j];
      }

      if (desh == 0) {
        if ((*word)[i] == ENG[j] && j <= 25) {
        codeword[i] = ENG[25 - j];
        }
      }
    }
  }

  if (fout == NULL) {
    printf("Atbash\n\n");
    printf("word: %s\n\n", *word);
    printf("rezult: %s\n", codeword);
    printf("\n\n");
  }
  else {
    fprintf(fout, "Atbash\n\n");
    fprintf(fout, "word: %s\n\n", *word);
    fprintf(fout, "rezult: %s\n", codeword);
    fprintf(fout,"\n\n");
  }

}
