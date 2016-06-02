#include "../include/vizhiner.h"

void vizhiner(const char *eng, const char *ENG,
              int lorr, int desh, FILE * fout, char ** word)
{
  int i, j, o, lenght = 0, klenght = 0, vvod = 1, mas = 1;

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

  char *kodword;
  kodword = (char *)malloc(sizeof(kodword));

  printf("\nEnter keyword\n");

  while (vvod == 1) {
    scanf("%c", &kodword[klenght]);

    if (kodword[klenght] == '\n') {
      kodword[klenght] = '\0';
      break;
    }

    kodword = (char *)realloc(kodword, ++klenght + 1);
  }

  int *ceas;
  ceas = (int *)malloc(klenght * sizeof(int));

  char *codeword = (char *)malloc(lenght * sizeof(char *));

  o = 0;
  for (i = 0; i < lenght; i++) {
    if((*word)[i] == ' ') {
      codeword[i] = ' ';
      continue;
    }

    if (o == klenght) {
      o = 0;
      mas = 0;
    }

    if (mas == 1) {
      for (j = 0; j < 28; j++) {
        if((kodword[o] == eng[j]) || (kodword[o] == ENG[j])) {
          ceas[o] = j;
          break;
        }
      }
    }

    for (j = 0; j < 28; j++) {
      if ((*word)[i] == eng[j]) {
        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas[o]) > 27) + (desh == 1) * ((j - ceas[o]) < 0)) {
            codeword[i] = eng[(desh == 0) * (j + ceas[o] - 28) + (desh == 1) * (j - ceas[o] + 28)];
            break;
          }
          else {
            codeword[i] = eng[(desh == 0) * (j + ceas[o]) + (desh == 1) * (j - ceas[o])];
            break;
          }
        }

        if (lorr == 0) {
          if ((desh == 0) * ((j-ceas[o]) < 0 ) + (desh == 1)*((j+ceas[o]) > 27)) {
            codeword[i] = eng[(desh == 0) * (j - ceas[o] + 28) + (desh == 1) * (j + ceas[o] - 28)];
            break;
          }
          else {
            codeword[i] = eng[(desh ==0) * (j - ceas[o]) + (desh == 1) * (j + ceas[o])];
            break;
          }
        }
      }

      if (((*word)[i] == ENG[j]) && (j <= 25)) {
        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas[o]) > 25) + (desh == 1) * ((j - ceas[o]) < 0)) {
            codeword[i] = ENG[(desh == 0) * (j + ceas[o] - 26) + (desh == 1) * (j - ceas[o] + 26)];
            break;
          }
          else {
            codeword[i] = ENG[(desh == 0) * (j + ceas[o]) + (desh == 1) * (j - ceas[o])];
            break;
          }
        }

        if (lorr == 0) {
          if((desh == 0) * ((j - ceas[o]) < 0) + (desh == 1) * ((j + ceas[o]) > 25)) {
            codeword[i] = ENG[(desh == 0) * (j - ceas[o] + 26) + (desh == 1) * (j + ceas[o] - 26)];
            break;
          }
          else {
            codeword[i] = ENG[(desh == 0) * (j - ceas[o]) + (desh == 1) * (j + ceas[o])];
            break;
          }
        }
      }
    }

    o++;

    if (i == lenght)
      break;
  }
  if (fout == NULL) {
    printf("Vizhiner\n\n");
    printf("word: %s\n\n", *word);
    printf("keyword: %s\n\n", kodword);
    printf("rezult: %s\n", codeword);
    printf("\n\n");
  }
  else {
    fprintf(fout, "Vizhiner\n\n");
    fprintf(fout, "word: %s\n\n", *word);
    fprintf(fout, "keyword: %s\n\n", kodword);
    fprintf(fout, "rezult: %s\n", codeword);
    fprintf(fout,"\n\n");
  }

  free(kodword);
  free(ceas);
}
