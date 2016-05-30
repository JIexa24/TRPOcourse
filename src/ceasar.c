#include "ceasar.h"

void ceasar(const char *eng, const char *ENG, int ceas,
            int lorr, int desh, FILE ** fout)
{
  int i,j,lenght = 0,vvod = 1;

  printf("%d", ceas);
  *fout = fopen("out.txt", "a");

  char *slovo;
  slovo = (char*)malloc(sizeof(slovo));

  fprintf(*fout, "Ceasar\n");
  fprintf(*fout, "\nSlovo:\n");

  printf("\nVvedite slovo\n");

  while (vvod == 1) {
    scanf("%c", &slovo[lenght]);

    if (slovo[lenght] == '\n')
      break;

    slovo = (char*)realloc( slovo, ++lenght+1 );
  }

  for(i = 0; i< lenght;i++)
    fprintf(*fout, "%c", slovo[i]);

  fprintf(*fout, "\n\nkluch: %d\n\n", ceas);
  fprintf(*fout, "rezult:\n");

  for (i = 0; i < lenght; i++) {
    if (slovo[i] == ' ') {
      fprintf(*fout," ");
      continue;
    }

    for (j = 0; j < 28; j++) {
      if (slovo[i] == eng[j]) {
        if (ceas > 28)
          for (ceas; ceas > 28; ceas = ceas-28);

        if( lorr == 1 ) {
          if ((desh == 0) * ((j + ceas) > 27) + (desh == 1) * ((j - ceas) < 0)) {
            fprintf(*fout, "%c", eng[(desh == 0) * (j + ceas - 28) + (desh == 1) * (j - ceas + 28)]);
          }
          else {
            fprintf(*fout, "%c", eng[(desh == 0) * (j + ceas) + (desh == 1) * (j - ceas)]);
          }
        }

        if( lorr == 0 )
        {
          if ((desh == 0) * ((j - ceas) < 0) + (desh == 1) * ((j + ceas) > 27)) {
            fprintf(*fout, "%c", eng[(desh == 0) * (j - ceas + 28) + (desh == 1) * (j + ceas - 28)]);
          }
          else {
            fprintf(*fout, "%c", eng[(desh == 0) * (j - ceas) + (desh == 1) * (j + ceas)]);
          }
        }
      }

      if (slovo[i]==ENG[j] && j <= 25) {
        if (ceas > 25)
          for (ceas; ceas > 25;ceas = ceas - 25);

        if (lorr==1) {
          if ((desh == 0) * ((j + ceas) > 25) + (desh == 1) * ((j - ceas) < 0)) {
            fprintf(*fout, "%c", ENG[(desh == 0)*(j + ceas - 26) + (desh == 1) * (j - ceas + 26)]);
          }
          else {
            fprintf(*fout, "%c", ENG[(desh == 0) * (j + ceas) + (desh == 1) * (j - ceas)]);
          }
        }

        if (lorr==0 )
        {
          if((desh == 0) * ((j - ceas) < 0) + (desh == 1) * ((j + ceas) > 25)) {
             fprintf(*fout, "%c", ENG[(desh == 0) * (j - ceas + 26) + (desh == 1) * (j + ceas - 26)]);
          }
          else {
             fprintf(*fout, "%c", ENG[(desh == 0) * (j - ceas) + (desh == 1) * (j + ceas)]);
          }
        }
      }
    }
  }

  fprintf(*fout, "\n\n");

  free(slovo);

  fclose(*fout);
}
