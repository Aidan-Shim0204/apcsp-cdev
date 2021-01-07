#include <stdio.h>
int main()
{
 int a = 545;
 char b = 'f'
 float c = 3.14
 double d = 49000
 printf("int a value: %d and size: %lu bytes\n" , a ,sizeof(a));
 printf("char b value: %d and size %lu bytes\n", b, sizeof(b));
 printf("float c value: %d and size %lu bytes\n", c , sizeof(c));
 printf("double d value: %d and size %lu bytes\n", d , sizeof(d));
}

