#include "../include/ceasar.h"

void ceasar(const char *eng, const char *ENG, int ceas,
            int lorr, int desh, FILE * fout, char ** word)
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

      *word = (char *)realloc(*word, ++lenght+1);
    }
  }
  else {
    lenght = strlen(*word);
  }


  char *codeword = (char *)malloc(lenght * sizeof(char *));

  for (i = 0; i < lenght; i++) {
    if ((*word)[i] == ' ') {
      codeword[i] = (*word)[i];
      continue;
    }

    for (j = 0; j < 28; j++) {
      if ((*word)[i] == eng[j]) {
        if (ceas > 28)
          for (ceas; ceas > 28; ceas = ceas-28);

        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas) > 27) + (desh == 1) * ((j - ceas) < 0)) {
            codeword[i] = eng[(desh == 0) * (j + ceas - 28) + (desh == 1) * (j - ceas + 28)];
            break;
          }
          else {
            codeword[i] = eng[(desh == 0) * (j + ceas) + (desh == 1) * (j - ceas)];
            break;
          }
        }

        if(lorr == 0)
        {
          if ((desh == 0) * ((j - ceas) < 0) + (desh == 1) * ((j + ceas) > 27)) {
            codeword[i] = eng[(desh == 0) * (j - ceas + 28) + (desh == 1) * (j + ceas - 28)];
            break;
          }
          else {
            codeword[i] = eng[(desh == 0) * (j - ceas) + (desh == 1) * (j + ceas)];
            break;
          }
        }
      }

      if ((*word)[i] == ENG[j] && j <= 25) {
        if (ceas > 25)
          for (ceas; ceas > 25;ceas = ceas - 25);

        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas) > 25) + (desh == 1) * ((j - ceas) < 0)) {
            codeword[i] = ENG[(desh == 0)*(j + ceas - 26) + (desh == 1) * (j - ceas + 26)];
            continue;
          }
          else {
            codeword[i] = ENG[(desh == 0) * (j + ceas) + (desh == 1) * (j - ceas)];
            continue;
          }
        }

        if (lorr ==0)
        {
          if ((desh == 0) * ((j - ceas) < 0) + (desh == 1) * ((j + ceas) > 25)) {
             codeword[i] = ENG[(desh == 0) * (j - ceas + 26) + (desh == 1) * (j + ceas - 26)];
             continue;
          }
          else {
             codeword[i] = ENG[(desh == 0) * (j - ceas) + (desh == 1) * (j + ceas)];
             continue;
          }
        }
      }
    }
  }
  if (fout == NULL) {
    printf("Ceasar\n\n");
    printf("word: %s\n\n", *word);
    printf("key: %d\n\n", ceas);
    printf("rezult: %s\n", codeword);
    printf("\n\n");
  }
  else {
    fprintf(fout, "Ceasar\n\n");
    fprintf(fout, "word: %s\n\n", *word);
    fprintf(fout, "key: %d\n\n", ceas);
    fprintf(fout, "rezult: %s\n", codeword);
    fprintf(fout,"\n\n");
  }
}
