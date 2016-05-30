#include "vizhiner.h"

void vizhiner(const char *eng, const char *ENG,
              int lorr, int desh, FILE ** fout)
{
  int i, j, o, lenght = 0, klenght = 0, vvod = 1, mas = 1;

  *fout = fopen("out.txt", "a");

  char *slovo;
  slovo = (char *)malloc(sizeof(slovo));

  fprintf(*fout, "Vizhiner\n\n");
  printf("\nVvedite slovo\n");

  while (vvod == 1) {
    scanf("%c", &slovo[lenght]);

    if( slovo[lenght] == '\n' )
      break;

    slovo = (char*)realloc(slovo, ++lenght + 1);
  }

  fprintf(*fout, "Slovo:\n");

  for (i = 0; i < lenght; i++)
   fprintf(*fout, "%c", slovo[i]);

  fprintf(*fout, "\n");

  char *kodslovo;
  kodslovo = (char *)malloc(sizeof(kodslovo));

  printf("\nVvedite kodslovo\n");

  while (vvod == 1) {
    scanf("%c", &kodslovo[klenght]);

    if (kodslovo[klenght] == '\n')
      break;

    kodslovo = (char *)realloc(kodslovo, ++klenght + 1);
  }

  fprintf(*fout, "\nKodslovo:\n");

  for (i = 0; i < klenght; i++)
    fprintf(*fout, "%c", kodslovo[i]);

  fprintf(*fout, "\n\n");
  fprintf(*fout, "rezult:\n");

  int *ceas;
  ceas = (int *)malloc(klenght * sizeof(int));

  o = 0;
  for (i = 0; i < lenght; i++) {
    if(slovo[i] == ' ') {
      fprintf(*fout, " ");
      continue;
    }

    if (o == klenght) {
      o = 0;
      mas = 0;
    }

    if (mas == 1) {
      for (j = 0; j < 28; j++) {
        if((kodslovo[o] == eng[j]) || (kodslovo[o] == ENG[j])) {
          ceas[o] = j;
          break;
        }
      }
    }

    for (j = 0; j < 28; j++) {
      if (slovo[i] == eng[j]) {
        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas[o]) > 27) + (desh == 1) * ((j - ceas[o]) < 0)) {
            fprintf(*fout, "%c", eng[(desh == 0) * (j + ceas[o] - 28) + (desh == 1) * (j - ceas[o] + 28)]);
            break;
          }
          else {
            fprintf(*fout, "%c", eng[(desh == 0) * (j + ceas[o]) + (desh == 1) * (j - ceas[o])]);
            break;
          }
        }

        if (lorr == 0) {
          if ((desh == 0) * ((j-ceas[o]) < 0 ) + (desh == 1)*((j+ceas[o]) > 27)) {
            fprintf(*fout, "%c", eng[(desh == 0) * (j - ceas[o] + 28) + (desh == 1) * (j + ceas[o] - 28)]);
            break;
          }
          else {
            fprintf(*fout, "%c", eng[(desh ==0) * (j - ceas[o]) + (desh == 1) * (j + ceas[o])]);
            break;
          }
        }
      }

      if ((slovo[i] == ENG[j]) && (j <= 25)) {
        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas[o]) > 25) + (desh == 1) * ((j - ceas[o]) < 0)) {
            fprintf(*fout, "%c", ENG[(desh == 0) * (j + ceas[o] - 26) + (desh == 1) * (j - ceas[o] + 26)]);
            break;
          }
          else {
            fprintf(*fout, "%c", ENG[(desh == 0) * (j + ceas[o]) + (desh == 1) * (j - ceas[o])]);
            break;
          }
        }

        if (lorr == 0) {
          if((desh == 0) * ((j - ceas[o]) < 0) + (desh == 1) * ((j + ceas[o]) > 25)) {
            fprintf(*fout, "%c", ENG[(desh == 0) * (j - ceas[o] + 26) + (desh == 1) * (j + ceas[o] - 26)]);
            break;
          }
          else {
            fprintf(*fout, "%c", ENG[(desh == 0) * (j - ceas[o]) + (desh == 1) * (j + ceas[o])]);
            break;
          }
        }
      }
    }

    o++;

    if (i == lenght)
      break;
  }

  fprintf(*fout, "\n\n");

  free(slovo);
  free(kodslovo);
  free(ceas);

  fclose(*fout);
}
