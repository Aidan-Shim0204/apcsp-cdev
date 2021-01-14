#include <stdio.h>
#include<math.h>


// add your areaOfCircle function here - it must NOT printf, instead it must
int areaOfCircle(int radius)
{
  
  float area;
   area = M_PI * radius * radius;
   printf("area at radius %d is equal to %f\n", radius, area);
}
// return the result to be printed in main




int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start;
  float end;
  char input[256]; 
  
  printf("Enter the lower bound: \n");
  
  while(1)
  {
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &start) == 1) break;
    printf("Not a valid input - do again\n");

  }
  printf("Enter the upper bound: \n");
  
  while(1)
  {
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &end) == 1) break;
    printf("Not a valid input - do again\n");
  }
   
  if (end <= start || end < 0)
  {
    printf("Input an upper bound that is positive or greater than the lower bound\n");
  }
  if (start < 0 || start >= end)
  {
    printf("Input a lower bound smaller than the upper bound and make your lower bound positive\n");
  }

  // for testing only - do not change

  printf("calculating area of circle starting at %f, and ending at %f\n", start, end);
  
  // add your code below to call areaOfCircle function with values between
  

for (float a = start; a <= end; a++)
{
  areaOfCircle(a);
}

  
}
