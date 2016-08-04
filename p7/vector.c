// Author: Janak Jobanputra & Janesh Gupta

#include "vector.h"
#include <stdlib.h>
int size=100, count=0;
int *crn = NULL;
char **subj=NULL;
char **courses=NULL;


void initialize()
{
  int i=0;
  crn = (int*) malloc(size*sizeof(int));
  subj = (char**) malloc(size*sizeof(char*));
  courses = (char**) malloc(size*sizeof(char*));
  for(i=0; i<size; i++)
  {
    subj[i] = (char*) malloc(4*sizeof(char));
    courses[i] = (char*) malloc(6*sizeof(char));
  } //end if malloc for subj and courses
} //end initialize

void resize()
{
  int i=0;
  int *newcrn = NULL;
  char **newsubj = NULL, **newcourses = NULL;
  int newsize = 2*size;
  newcrn = (int*) malloc(newsize*sizeof(int));
  newsubj = (char**) malloc(newsize*sizeof(char*));
  newcourses = (char**) malloc(newsize*sizeof(char*));
  for(i=0; i<size; i++)
  {
    newcrn[i] = crn[i];
    newsubj[i] = subj[i];
    newcourses[i] = courses[i];
    newsubj[i+size] = (char*) malloc(4+sizeof(char));
    newcourses[i+size] = (char*) malloc(6*sizeof(char));
  } //end if malloc for subj and courses
  free(crn);
  free(subj);
  free(courses);
  crn = newcrn;
  subj = newsubj;
  courses = newcourses;
  size = newsize;
} //end resize

void deallocate()
{
  int i=0;
  free(crn);
  for(i=0; i<size; i++)
  {
    free(subj[i]);
    free(courses[i]);
  } //end for free
  free(subj);
  free(courses);
} //end deallocate
