#include "../include/atbash_test.h"

extern const char *eng;
extern const char *ENG;

int ATBATEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = ".,zyxwvutsr";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("ATBA TEST 1: success\n");
    return 0;
  }
  else {
    printf(TEST_FAIL);
    printf("ATBA TEST 1: error\n");
    return 1;
  } 
}

int ATBATEST2()
{
  char *array = "word";
  char *onetestarray = "fnky";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("ATBA TEST 2: success\n");
    return 0;
  }
  else {
    printf(TEST_FAIL);
    printf("ATBA TEST 2: error\n");
    return 1;
  } 
}

int ATBATEST3()
{
  char *array = "";
  char *onetestarray = "";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("ATBA TEST 3: success\n");
    return 0;
  }
  else {
    printf(TEST_FAIL);
    printf("ATBA TEST 3: error\n");
    return 1;
  } 
}

int ATBATEST4()
{
  char *array = "\n";
  char *onetestarray = "\n";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf(TEST_OK);
    printf("ATBA TEST 4: success\n");
    return 0;
  }
  else {
    printf(TEST_FAIL);
    printf("ATBA TEST 4: error\n");
    return 1;
  } 
}
