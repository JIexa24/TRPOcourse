#include "../include/vizhiner_test.h"

extern const char *eng;
extern const char *ENG;

void VIZHTEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = "acceeggiikk";
  char *key = "ab";
  int lorr = 1;
  int desh = 0;
  char *testarray = vizhiner(eng, ENG, lorr, desh, NULL, &array, &key, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("VIZH TEST 1: success\n");
  }
  else {
    printf("VIZH TEST 1 : error\n");

  } 
}

void VIZHTEST2()
{
  char *array = "attackatdawn";
  char *onetestarray = "lxdopvedrnfr";
  char *key = "lemon";
  int lorr = 1;
  int desh = 0;
  char *testarray = vizhiner(eng, ENG, lorr, desh, NULL, &array, &key, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("VIZH TEST 2: success\n");
  }
  else {
    printf("VIZH TEST 2 : error\n");

  } 
}

void VIZHTEST3()
{
  char *array = "";
  char *onetestarray = "";
  char *key = "";
  int lorr = 1;
  int desh = 0;
  char *testarray = vizhiner(eng, ENG, lorr, desh, NULL, &array, &key, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("VIZH TEST 3: success\n");
  }
  else {
    printf("VIZH TEST 3 : error\n");

  } 
}

void VIZHTEST4()
{
  char *array = "\n";
  char *onetestarray = "\n";
  char *key = "a";
  int lorr = 1;
  int desh = 0;
  char *testarray = vizhiner(eng, ENG, lorr, desh, NULL, &array, &key, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("VIZH TEST 4: success\n");
  }
  else {
    printf("VIZH TEST 4 : error\n");

  } 
}
