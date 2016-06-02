#include "../include/ceasar_test.h"

#define CEASAR_TEST

 const char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  const char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

void TEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = "cdefghijklm";
  int ceas = 2;          
  int lorr = 1;
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, t, &array);
  if (!(strcmp(onetestarray, testarray))) {
    printf("TEST 1: success\n");
  }
  else {
    printf("TEST 1 : error\n");

  } 
}

void TEST2()
{
  char *array = "word";
  char *onetestarray = "ey.n";
  int ceas = 10;          
  int lorr = 1;
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, t, &array);
  if (!(strcmp(onetestarray, testarray))) {
    printf("TEST 2: success\n");
  }
  else {
    printf("TEST 2 : error\n");

  } 
}

int main()
{
  TEST1();
  printf("\n");
  TEST2();
  return 0;
}
