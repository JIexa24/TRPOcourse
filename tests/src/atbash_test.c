#include "../include/atbash_test.h"

extern const char *eng;
extern const char *ENG;

void ATBATEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = ".,zyxwvutsr";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("ATBA TEST 1: success\n");
  }
  else {
    printf("ATBA TEST 1 : error\n");

  } 
}

void ATBATEST2()
{
  char *array = "word";
  char *onetestarray = "fnky";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("ATBA TEST 2: success\n");
  }
  else {
    printf("ATBA TEST 2 : error\n");
  } 
}

void ATBATEST3()
{
  char *array = "";
  char *onetestarray = "";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("ATBA TEST 3: success\n");
  }
  else {
    printf("ATBA TEST 3 : error\n");
  } 
}

void ATBATEST4()
{
  char *array = "\n";
  char *onetestarray = "\n";
  int desh = 0;
  char *testarray = atbash(eng, ENG, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("ATBA TEST 4: success\n");
  }
  else {
    printf("ATBA TEST 4 : error\n");

  } 
}
