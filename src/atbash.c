#include "../include/atbash.h"

extern const char *eng;
extern const char *ENG;
extern const char *sym;

char *atbash(int result, char *word, FILE *fout) {
  int length = strlen(word);
  int i = 0;
  int j = 0;
  int replace_flag = 0;
  char *codeword = (char *)malloc(sizeof(char) * length);

  for (i = 0; i < length; ++i) {
    replace_flag = 0;
    for (j = 0; j < strlen(eng); ++j) {
      if (word[i] == eng[j]) {
        codeword[i] = eng[strlen(eng) - j - 1];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(ENG); ++j) {
      if (word[i] == ENG[j]) {
        codeword[i] = ENG[strlen(ENG) - j - 1];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(sym); ++j) {
      if (word[i] == sym[j]) {
        codeword[i] = sym[strlen(sym) - j - 1];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
  }

  if (result == 1) {
    if (fout == NULL)
      fout = stdout;
    fprintf(fout, "Atbash\n\n");
    fprintf(fout, "Word: %s\n\n", word);
    fprintf(fout, "Rezult: %s\n", codeword);
    fprintf(fout, "\n\n");
  }
  return codeword;
}
