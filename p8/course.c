// Authors: Janak Jobanputra & Janesh Gupta

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "rsvp.h"
#include "course.h"
#include "vector.h"

void read_courses(char* filename, Course **courses, int *size, int *count)
{
  FILE* inp = fopen(filename, "r");
  if(inp == NULL)
  {
    printf("FILE 1 COULD NOT BE OPENED.\n");
    exit(1);
  } //end if file error

  char temp[1000] = {};
  while(1)
  { 
    fgets(temp, 1000, inp);
    if(strstr(temp, "UNIVERSITY OF CALIFORNIA, DAVIS"))
      break;
  } //end while fgets
  int i=0;  
  for(i=0; i<5; i++)
  {
    fgets(temp, 1000, inp);
  } //end trash scanning
  char* ptr;

  while(1)
  {
    fgets(temp, 1000, inp);
    if(strstr(temp, "</pre>"))
      break;
    if(isdigit(temp[0]))
    {
      if(*count >= *size)
        resize(courses, size, count);
      ptr = strtok(temp, "\t ^");
      (*courses)[*count].crn = atoi(ptr);
      ptr = strtok(NULL, "\t ^");
      strcpy((*courses)[*count].subj, ptr);
      ptr = strtok(NULL, "\t ^");
      strcpy((*courses)[*count].course_no, ptr);
      (*count)++;
    } // end if line is correct
  } // while scanning for data
  fclose(inp);
} //end read_courses

void find_CRN(Course *courses, int count, Student *students, int count_stud)
{
  int i=0, course_num=0;
  printf("Please enter a CRN: ");
  scanf("%d", &course_num);
  for(i=0; i<(count); i++)
  {
    if(course_num == courses[i].crn)
    {
      printf("%s %s\n", courses[i].subj, courses[i].course_no);
      for(i=0;i<count_stud;i++)
      {
        int j=0;
        for(j=0;j< students[i].count_classes;j++)
        {
          if(students[i].crn[j] == course_num)
            printf("%s %s\n", students[i].last, students[i].first);
        }
      }
      return;
    }
    
  } //end for scan crn
  printf("CRN %d not found.\n", course_num);
} //end find_CRN

void find_subject(Course *courses, int count)
{
  int i=0, flag=0;
  char temp[5];
  printf("Please enter a subject: ");
  scanf("%s", temp);
  for(i=0; i<(count); i++)
  {
    if(!strcmp(courses[i].subj, temp))
    {
      printf("%d %s %s\n", courses[i].crn, courses[i].subj,
        courses[i].course_no);
      flag=1;
    }
  } //end for scan crn
  if(flag==0)
    printf("No courses were found for %s\n", temp);
} //end find_subject
