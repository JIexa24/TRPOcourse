#include "../include/ceasar_test.h"

extern const char *eng;
extern const char *ENG;

int CEASTEST1() {
  char *array = "abcdefghijk";
  char *onetestarray = "cdefghijklm";
  int key = 2;
  int vector = 1;
  int decode = 1;
  char *testarray = ceasar(key, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("CEAS TEST 1: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("CEAS TEST 1: error\n");
    return 1;
  }
}

int CEASTEST2() {
  char *array = "word";
  char *onetestarray = "gybn";
  int key = 10;
  int vector = 1;
  int decode = 1;
  char *testarray = ceasar(key, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("CEAS TEST 2: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("CEAS TEST 2: error\n");
    return 1;
  }
}

int CEASTEST3() {
  char *array = "";
  char *onetestarray = "";
  int key = 2;
  int vector = 1;
  int decode = 1;
  char *testarray = ceasar(key, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("CEAS TEST 3: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("CEAS TEST 3: error\n");
    return 1;
  }
}

int CEASTEST4() {
  char *array = "\n";
  char *onetestarray = "";
  int key = 2;
  int vector = 1;
  int decode = 1;
  char *testarray = ceasar(key, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("CEAS TEST 4: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("CEAS TEST 4: error\n");
    return 1;
  }
}
