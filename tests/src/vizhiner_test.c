#include "../include/vizhiner_test.h"

extern const char *eng;
extern const char *ENG;

int VIZHTEST1() {
  char *array = "abcdefghijk";
  char *onetestarray = "acceeggiikk";
  char *keyword = "ab";
  int vector = 1;
  int decode = 1;
  char *testarray = vizhiner(keyword, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("VIZH TEST 1: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("VIZH TEST 1: error\n");
    return 1;
  }
}

int VIZHTEST2() {
  char *array = "attackatdawn";
  char *onetestarray = "lxfopvefrnhr";
  char *keyword = "lemon";
  int vector = 1;
  int decode = 1;
  char *testarray = vizhiner(keyword, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("VIZH TEST 2: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("VIZH TEST 2: error\n");
    return 1;
  }
}

int VIZHTEST3() {
  char *array = "";
  char *onetestarray = "";
  char *keyword = "";
  int vector = 1;
  int decode = 0;
  char *testarray = vizhiner(keyword, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("VIZH TEST 3: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("VIZH TEST 3: error\n");
    return 1;
  }
}

int VIZHTEST4() {
  char *array = "\n";
  char *onetestarray = "";
  char *keyword = "a";
  int vector = 1;
  int decode = 0;
  char *testarray = vizhiner(keyword, vector, decode, 0, array, NULL);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("VIZH TEST 4: success\n");
    return 0;
  } else {
    printf(TEST_FAIL);
    printf("VIZH TEST 4: error\n");
    return 1;
  }
}
