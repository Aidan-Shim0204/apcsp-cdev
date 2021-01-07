#include <stdio.h>

int main()
{
   for (int div = 0; div <= 100; div++)
   { 
      if (div % 10 == 0 && div >= 10)
       { 
         printf("%d is divisible by 10\n",div);
       }

   }



}
