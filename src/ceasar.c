#include "../include/ceasar.h"

extern const char *eng;
extern const char *ENG;
extern const char *sym;

char *ceasar(int key, int vector, int decode, int result, char *word,
             FILE *fout) {
  int length = strlen(word);
  int i = 0;
  int j = 0;
  int replace_flag = 0;
  char *codeword = (char *)malloc(sizeof(char) * length);
  vector = vector > 0 ? 1 : -1;
  decode = decode > 0 ? 1 : -1;
  for (i = 0; i < length; ++i) {
    replace_flag = 0;
    for (j = 0; j < strlen(eng); ++j) {
      if (word[i] == eng[j]) {
        codeword[i] =
            eng[(j + vector * decode * key + strlen(eng)) % strlen(eng)];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(ENG); ++j) {
      if (word[i] == ENG[j]) {
        codeword[i] =
            ENG[(j + vector * decode * key + strlen(ENG)) % strlen(ENG)];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(sym); ++j) {
      if (word[i] == sym[j]) {
        codeword[i] =
            sym[(j + vector * decode * key + strlen(sym)) % strlen(sym)];
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
    fprintf(fout, "Ceasar\n\n");
    if (decode < 0)
      fprintf(fout, "!--Decoding--!\n\n");
    fprintf(fout, "Word: %s\n\n", word);
    fprintf(fout, "Key: %d\n\n", key);
    fprintf(fout, "Rezult: %s\n", codeword);
    fprintf(fout, "\n\n");
  }
  return codeword;
}
