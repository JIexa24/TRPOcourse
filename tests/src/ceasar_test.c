#include "../include/ceasar_test.h"

extern const char *eng;
extern const char *ENG;

int CEASTEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = "cdefghijklm";
  int ceas = 2;          
  int lorr = 1;
  int desh = 0;
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("CEAS TEST 1: success\n");
    return 0;
  }
  else {
    printf("CEAS TEST 1 : error\n");
    return 1;
  } 
}

int CEASTEST2()
{
  char *array = "word";
  char *onetestarray = "ey.n";
  int ceas = 10;          
  int lorr = 1;
  int desh = 0;
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("CEAS TEST 2: success\n");
    return 0;
  }
  else {
    printf("CEAS TEST 2 : error\n");
    return 1;
  } 
}

int CEASTEST3()
{
  char *array = "";
  char *onetestarray = "";
  int ceas = 2;          
  int lorr = 1;
  int desh = 0;
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("CEAS TEST 3: success\n");
    return 0;
  }
  else {
    printf("CEAS TEST 3 : error\n");
    return 1;
  } 
}

int CEASTEST4()
{
  char *array = "\n";
  char *onetestarray = "\n";
  int ceas = 2;          
  int lorr = 1;
  int desh = 0;
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, NULL, &array, 0);

  if (!(strcmp(onetestarray, testarray))) {
    printf("CEAS TEST 4: success\n");
    return 0;
  }
  else {
    printf("CEAS TEST 4 : error\n");
    return 1;
  } 
}
