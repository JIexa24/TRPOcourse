#include "../include/atbash.h"

void atbash(const char *eng, const char *ENG,
            int desh, FILE ** fout)
{
  int i,j,lenght = 0,vvod = 1;

  *fout = fopen("out.txt", "a");
  fprintf(*fout, "Atbash\n\n");

  char *slovo;
  slovo = (char*)malloc(sizeof(slovo));

  fprintf(*fout, "Word:\n");
  printf("\nEnter word\n");

  while (vvod) {
    scanf("%c", &slovo[lenght]);

    if (slovo[lenght] == '\n') {
      slovo[lenght] = '\0';
      break;
    }

    slovo = (char*)realloc(slovo, ++lenght+1);
  }

  for (i = 0; i < lenght; i++)
    fprintf(*fout, "%c", slovo[i]);

  fprintf(*fout, "\n\n");
  fprintf(*fout, "rezult:\n");

  for (i = 0; i < lenght; i++) {
    if (slovo[i] == ' ') {
      fprintf(*fout, " ");
      continue;
    }

    for (j = 0; j < 28; j++) {
      if (slovo[i] == eng[j]) {
        fprintf(*fout, "%c", eng[27 - j]);
      }

      if (desh == 0) {
        if (slovo[i] == ENG[j] && j <= 25) {
          fprintf(*fout, "%c", ENG[25-j]);
        }
      }
    }
  }

  fprintf(*fout,"\n\n");

  free(slovo);

  fclose(*fout);
}
