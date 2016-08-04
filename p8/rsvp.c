// Authors: Janak Jobanputra & Janesh Gupta

#include <stdio.h>
#include "rsvp.h"
#include "course.h"
#include "vector.h"
#include "student.h"

int main(int argc, char *argv[])
{
  int size=100, count=0;
  int size_stud=10, count_stud=0;
  Course *courses=NULL;
  Student *students=NULL;
  initialize(&courses, &size);
  initialize_stud(&students, &size_stud);
  read_courses(argv[1], &courses, &size, &count);
  read_students(argv[2], &students, &size_stud, &count_stud);
  display_info(courses, count, students, count_stud);
  deallocate(&courses, &size, &count);
  deallocate_stud(&students, &size, &count);
  return 0;
} //end main

int get_choice()
{
  int choice=0;
  printf("RSVP Menu\n");
  printf("0. Done.\n");
  printf("1. Find by CRN.\n");
  printf("2. Find by Subject. \n");
  printf("3. Add Course. \n");
  printf("4. Remove Course. \n");
  printf("Your choice (0 - 4): ");
  scanf("%d", &choice);
  //printf("Your choice was %d\n", choice);
  if(choice<0 || choice>4)
    printf("Your choice is outside the acceptable range. Please try again\n");
  return choice;
} //end get_choice

void display_info(Course *courses, int count, Student *students, int count_stud)
{
  while(1)
  {
    int choice=0;

    choice = get_choice();

    if(choice == 0)
      break;

    if(choice == 1)
      find_CRN(courses, count, students, count_stud);

    if(choice == 2)
      find_subject(courses, count);

    if(choice == 3)
      add_course(students, count_stud, courses, count);

    if(choice == 4)
      rm_course(students, count_stud, courses, count);
      
    printf("\n");
  } //end while
} //end display_info
