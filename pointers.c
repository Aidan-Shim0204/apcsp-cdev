#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;
  float* ptrtod;
  float* ptrtoe;
  float d = 3.14;
  float e = 2.89;
  

  ptrtoa = &a;
  ptrtod = &d;
  ptrtoe = &e;
  a = 5;
  d = 1.55;
  e = 5.6;

  printf("The value of a is %d\n", a);
  printf("The value of d is %d\n", d);
  printf("The value of e is %e\n", e);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  printf("The value of ptrtod is %p\n", (void*)ptrtod);
  printf("It stores the value %d\n", *ptrtod);
  printf("The address of d is %p\n", (void*)&d);
 
  printf("The value of ptrtoe is %p\n", (void*)ptrtoe);
  printf("It stores the value %d\n", *ptrtoe);
  printf("The address of e is %p\n", (void*)&e);

  int b = *ptrtod;
  int c = *ptrtoe;
  *ptrtod = e;
  *ptrtoe = d;
  
   printf("D is now %d and E is now %d\n", b, c); 
}
