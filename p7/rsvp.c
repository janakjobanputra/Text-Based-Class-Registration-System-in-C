// Authors: Janak Jobanputra & Janesh Gupta

#include <stdio.h>
#include "rsvp.h"
#include "course.h"
#include "vector.h"


int main(int argc, char *argv[])
{
  initialize();
  read_courses(argv[1]);
  display_info();
  deallocate();
  return 0;
} //end main

void get_choice(int *choice)
{
  printf("RSVP Menu\n");
  printf("0. Done.\n");
  printf("1. Find by CRN.\n");
  printf("2. Find by Subject \n");
  printf("Your choice (0 - 2): ");
  scanf("%d", choice);
  //printf("Your choice was %d\n", choice);
  if(*choice<0 || *choice>2)
  {
    printf("Your choice is outside the acceptable range. Please try again\n");
  }

} //end get_choice

void display_info()
{
  while(1)
  {
    int choice=0;
    get_choice(&choice);
    if(choice == 0)
    {
//      printf("You are done.\n");
      break;
    } //end if choice=0

    if(choice == 1)
    {
//      printf("Your choice was to find by CRN.\n");
      find_CRN();
    } //end if choice=1

    if(choice == 2)
    {
//      printf("Your choice was to find by subject.\n");
      find_subject();
    } //end if choice=2

    printf("\n");
  } //end while
} //end display_info
