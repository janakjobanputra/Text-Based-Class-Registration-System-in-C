// Authors: Janak Jobanputra & Janesh Gupta

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "course.h"
#include "rsvp.h"
#include "vector.h"

void read_courses(char* filename)
{
  FILE* inp = fopen(filename, "r");
  if(inp == NULL)
  {
    printf("FILE COULD NOT BE OPENED.\n");
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
      if(count>=size)
        resize();
      ptr = strtok(temp, "\t ^");
      crn[count] = atoi(ptr);
      ptr = strtok(NULL, "\t ^");
      strcpy(subj[count], ptr);
      ptr = strtok(NULL, "\t ^");
      strcpy(courses[count], ptr);
      //printf("%d %s %s\n", crn[count], subj[count], courses[count]);
      count++;
    } // end if line is correct
  } // while scanning for data
  fclose(inp);
} //end read_courses

void find_CRN()
{
  int i=0, course_no=0;
  printf("Please enter a CRN: ");
  scanf("%d", &course_no);
  for(i=0; i<count; i++)
  {
    if(course_no == crn[i])
    {
      printf("%s %s\n", subj[i], courses[i]);
      return;
    }
    
  } //end for scan crn
  printf("CRN %d not found.\n", course_no);
} //end find_CRN

void find_subject()
{
  int i=0, flag=0;
  char temp[5];
  printf("Please enter a subject: ");
  scanf("%s", temp);
  for(i=0; i<count; i++)
  {
    if(strcmp(subj[i], temp) == 0)
    {
      printf("%d %s %s\n", crn[i], subj[i], courses[i]);
      flag=1;
    }
  } //end for scan crn
  if(flag==0)
    printf("No courses were found for %s\n", temp);
} //end find_subject
