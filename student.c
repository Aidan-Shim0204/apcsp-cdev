
#include <stdio.h>

struct Student{
   char firstname[50];
   char lastname[50];
   int age;
   int studentid;
};

void printStudent(struct Student* students)
{
  printf("First name:%s\n", students->firstname);
  printf("Last name:%s\n", students->lastname);
  printf("Age is:%d\n", students->age);
  printf("Id is:%d\n", students->studentid);
}


void printAllStudents(struct Student students[], int numStudents)
{
 for (int i = 0; i < numStudents; i++)
 {
  printf("----student----\n");
  printStudent(&(students[i]));

    
 }// call printStudent for each student in students\

   
}

int main()
{

  // an array of students
  //xxx students;
  int numStudents = 0;
  char input[256];
  struct Student students[256];


  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("First name:\n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &(students[numStudents].firstname));
      
        
      printf("Last name:\n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &(students[numStudents].lastname));

     printf("Age:\n");
     fgets(input, 256, stdin);
     if (sscanf(input, "%d", &(students[numStudents].age))!=1) continue;


     printf("Student_id:\n");
     fgets(input, 256, stdin);
     if (sscanf(input, "%d", &(students[numStudents].studentid))!=1) continue;

      numStudents++;
    }
  }
  printf("\nGoodbye!\n");
}
