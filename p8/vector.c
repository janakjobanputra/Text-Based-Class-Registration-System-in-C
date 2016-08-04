// Author: Janak Jobanputra & Janesh Gupta

#include "rsvp.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initialize(Course **courses, int *size)
{
  *courses = (Course*) malloc((*size)*sizeof(Course));
} //end initialize

void resize(Course **courses, int *size, int *count)
{
  int i=0;
  Course *newcourses;
  int newsize = 2*(*size);
  newcourses = (Course*) malloc(newsize*sizeof(Course));
  for(i=0;i<*size;i++)
  {
    newcourses[i].crn = (*courses)[i].crn;
    strcpy(newcourses[i].subj, (*courses)[i].subj);
    strcpy(newcourses[i].course_no, (*courses)[i].course_no);
  } //end for loop, coping old to new
  free(*courses);
  *size = newsize;
  *courses = newcourses;
} //end resize

void deallocate(Course **courses, int *size, int *count)
{
  free(*courses);
  *size = 0;
  *count =0;
} //end deallocate
