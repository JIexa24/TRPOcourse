#include "../include/vizhiner.h"
extern const char *eng;
extern const char *ENG;
extern const char *sym;
char *vizhiner(char *keyword, int vector, int decode, int result, char *word,
               FILE *fout) {
  int length = strlen(word);
  int keylength = strlen(keyword);
  int i = 0;
  int j = 0;
  int replace_flag = 0;
  char *codeword = (char *)malloc(sizeof(char) * length);
  int *offsets = (int *)malloc(sizeof(int) * keylength);
  vector = vector > 0 ? 1 : -1;
  decode = decode > 0 ? 1 : -1;

  for (i = 0; i < keylength; ++i) {
    replace_flag = 0;
    for (j = 0; j < strlen(eng); ++j) {
      if (keyword[i] == eng[j]) {
        offsets[i] = j;
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(ENG); ++j) {
      if (keyword[i] == ENG[j]) {
        offsets[i] = j;
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(sym); ++j) {
      if (keyword[i] == sym[j]) {
        offsets[i] = j;
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
  }

  for (i = 0; i < length; ++i) {
    replace_flag = 0;
    for (j = 0; j < strlen(eng); ++j) {
      if (word[i] == eng[j]) {
        codeword[i] =
            eng[(j + vector * decode * offsets[i % keylength] + strlen(eng)) %
                strlen(eng)];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(ENG); ++j) {
      if (word[i] == ENG[j]) {
        codeword[i] =
            ENG[(j + vector * decode * offsets[i % keylength] + strlen(ENG)) %
                strlen(ENG)];
        replace_flag = 1;
        break;
      }
    }
    if (replace_flag)
      continue;
    for (j = 0; j < strlen(sym); ++j) {
      if (word[i] == sym[j]) {
        codeword[i] =
            sym[(j + vector * decode * offsets[i % keylength] + strlen(sym)) %
                strlen(sym)];
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
    fprintf(fout, "Vizhiner\n\n");
    if (decode < 0)
      fprintf(fout, "!--Decoding--!\n\n");
    fprintf(fout, "Word: %s\n\n", word);
    fprintf(fout, "Key: %s\n\n", keyword);
    fprintf(fout, "Rezult: %s\n", codeword);
    fprintf(fout, "\n\n");
  }
  return codeword;
}
