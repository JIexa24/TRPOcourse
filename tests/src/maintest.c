#include <stdio.h>
#include <string.h>

#include "../include/ceasar_test.h"
#include "../include/vizhiner_test.h"
#include "../include/atbash_test.h"

#define TESTS

 const char *eng = "abcdefghijklmnopqrstuvwxyz,.";
 const char *ENG = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
  int error = 0;
  error += CEASTEST1();
  error += CEASTEST2();
  error += CEASTEST3();
  error += CEASTEST4();

  printf("\n\n");

  error += VIZHTEST1();
  error += VIZHTEST2();
  error += VIZHTEST3();
  error += VIZHTEST4();

  printf("\n\n");

  error += ATBATEST1();
  error += ATBATEST2();
  error += ATBATEST3();
  error += ATBATEST4();

  return error > 0 ? 1 : 0;
}
