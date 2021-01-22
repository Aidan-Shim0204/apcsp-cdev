//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* student = (Student*)malloc(sizeof(Student));
  student->firstName = (char*) malloc(strlen(fname)*sizeof(char));
  student->lastName = (char*) malloc(strlen(lname)*sizeof(char));
  student->age = age;
  student->id = id;
  
  strcpy(student->firstName, fname);
  strcpy(student->lastName, lname); 
  students[numStudents] = student;
  numStudents++;
}




void deleteStudent(Student* student)
{
  free(student->firstName);
  free(student->lastName);
  free(student); 
  // free the memory associated with a student including the strings
}


void deleteStudents()
{
   // iterate over the students array deleting every student and setting te pointer
   // values to 0 and adjusting the numStudents to 0
  for (int i = 0; i < numStudents; i++){
       deleteStudent(students[i]);
       students[i] = 0;
   }
  numStudents = 0;
}



void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  FILE* fp;
  char buffer[256];
  fp = fopen("studentdata.txt", "w+");
  if(fp){
    for(int i =0; i < numStudents; i++){
       Student* student = students[i];
        sprintf(buffer,"%s %s %u %ld\n", student->firstName, student->lastName, student->age, student->id);
        
	caesarEncrypt(buffer,key);
        
	fprintf(fp,"%s", buffer);
         
        printf("saving: %s %s %u %ld\n", student->firstName, student->lastName, student->age, student->id);
        
    }
    fclose(fp);
  

  }
  
}
void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  deleteStudents();
  char b1[256];
  char b2[256];
  char b3[256];
  char b4[256];  
  FILE* fp; 
  fp = fopen("studentdata.txt", "r");
  if(fp){
     
     int match = fscanf(fp, "%s %s %s %s\n", b1, b2, b3, b4);
     while (match == 4){
       if(key != 0){
        caesarDecrypt(b1, key);
        caesarDecrypt(b2, key);
        caesarDecrypt(b3, key);
        caesarDecrypt(b4, key);
        
        
     }
     unsigned int age;
     long id;
     
     sscanf(b3, "%u", &age);
     sscanf(b4, "%ld", &id);
  
     createStudent(b1, b2, age, id);
     printf("loading: %d\n", numStudents);
     match = fscanf(fp, "%s %s %s %s\n", b1, b2, b3, b4);
    }
   fclose(fp);

  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




