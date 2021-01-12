#include <stdio.h>
#include <string.h>

int main()
{
  char str1[30];
  char str2[30] = "abcdefghijklmnopqrstuvwxyz";
  char str3[30];

  for (int i = 0; i < 26; i++)
   {
     str1[i] = 'a' + i;

   }
   str1[26] = '\0';

 
   printf("the second string is: %s\n", str2);
 
   

  
  for (int j = 0; j <26; j++)
  { 
     str1[j] = str1[j] -= 32;
  } 

  strcpy(str3, str2);
  strcat(str3, str1);

  if (strcmp(str1, str2) == 0)
   printf("the strings are identical\n");
  else
   printf("the strings are different\n");
    
  
  printf("first string is: %s\n", str1);
  printf("combined, the string is: %s\n", str3);

}

