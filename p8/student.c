//Authors: Janak Jobanputra & Janesh Gupta

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rsvp.h"
#include "student.h"

void initialize_stud(Student **students, int *size_stud)
{
  *students = (Student*) malloc((*size_stud)*sizeof(Student));
} //end initialize_stud

void resize_stud(Student **students, int *size_stud, int *count_stud)
{
  int i=0, j=0;
  Student *newstudents;
  int newsize_stud = 2*(*size_stud);
  newstudents = (Student*) malloc(newsize_stud*sizeof(Student));
  for(i=0;i<*size_stud;i++)
  {
    newstudents[i].last = (*students)[i].last;
    newstudents[i].first = (*students)[i].first;
    strcpy(newstudents[i].ssid, (*students)[i].ssid);
    newstudents[i].count_classes = (*students)[i].count_classes;
    for(j=0;j<newstudents[i].count_classes; j++)
      newstudents[i].crn[j] = (*students)[i].crn[j];
  }// end for loop
  free(*students);
  *size_stud = newsize_stud;
  *students = newstudents;
} //end resize_stud

void deallocate_stud(Student **students, int *size_stud, int *count_stud)
{
  int i=0;
  for(i=0;i<*count_stud;i++)
  {
    free((*students)[i].last);
    free((*students)[i].first);
  } 
  free(*students);
} //end deallocate_stud

void read_students(char* filename_stud, Student **students, int *size_stud,
  int *count_stud)
{
  FILE* inp_stud = fopen(filename_stud, "r");
  if(inp_stud == NULL)
  {
    printf("FILE 2 COULD NOT BE OPENED.\n");
    exit(1);
  } //end if file error
  int i=0;
  char temp[1000]={};
  char *ptr;
  while(fgets(temp, 1000, inp_stud))
  {
    if(*count_stud >= *size_stud)
      resize_stud(students, size_stud, count_stud);
    ptr = strtok(temp, ",\n");
    (*students)[*count_stud].last=\
      (char*)malloc((strlen(ptr)+1)*sizeof(char));
    strcpy((*students)[*count_stud].last, ptr);
    ptr = strtok(NULL, ",\n");
    (*students)[*count_stud].first=\
      (char*) malloc((strlen(ptr)+1)*sizeof(char));
    strcpy((*students)[*count_stud].first, ptr);
    ptr = strtok(NULL, ",\n");
    strcpy((*students)[*count_stud].ssid, ptr);
    //printf("%s\n", (*students)[*count_stud].ssid);
    i=0;
    int *crntemp=(*students)[*count_stud].crn;
    (*students)[*count_stud].count_classes=0;
    while((ptr = strtok(NULL, ",\n"))!=NULL)
    {
      //printf("%d\n", atoi(ptr));
      crntemp[i]= atoi(ptr);
      (*students)[*count_stud].count_classes+=1;
      //printf("CRN: %d\n", crntemp[i]);
      i++;
    } //end while crn strtok
    //printf("%d\n", (*students)[*count_stud].count_classes);
    //printf("Count_stud = %d\n", *count_stud);
    (*count_stud)++;
  } //end while input
  fclose(inp_stud);
} //end read_students

void add_course(Student *students, int count_stud, Course *courses, int count)
{
  char ssidtemp[15]={};
  int  crntemp=0;
  printf("Add Course\n");
  printf("Please enter the SID of the student: ");
  scanf("%s", ssidtemp);
  //printf("Your SSID is %s\n", ssidtemp);
  int ssid_loc=0, flag=0;
  for(ssid_loc=0; ssid_loc< count_stud; ssid_loc++)
  {
    if(!strcmp(students[ssid_loc].ssid, ssidtemp))
    {
      flag=1;
      break;
    }
  } //check if sid exists
  if(flag==0)
  {
    printf("NO SUCH SSID WAS FOUND.\n");
    return;
  }
  if(students[ssid_loc].count_classes >= 5)
  {
    printf("You are already taking 5 courses.\n");
    return;
  }
  printf("Please enter the CRN: ");
  scanf("%d", &crntemp);
  int i=0, flag_course=0;
  for(i=0;i<count;i++)
  {
    if(crntemp == courses[i].crn)
      flag_course=1;
  }
  if(flag_course ==0)
  {
    printf("There is no course with CRN #%d\n", crntemp);
    return;
  }
  flag=0;
  for(i=0;i<students[ssid_loc].count_classes;i++)
  {
    if(crntemp == students[ssid_loc].crn[i])
      flag=1;
  }
  if(flag ==1)
  {
    printf("You are already registered for this course.\n");
    return;
  }
  if(flag==0)
  {
    students[ssid_loc].crn[(students[ssid_loc].count_classes)] = crntemp;
    students[ssid_loc].count_classes++;
  }
  //printf("Your CRN is %s\n", crntemp);
  return;

} //end add_course

void rm_course(Student *students, int count_stud, Course *courses, int count)
{
  char ssidtemp[15]={};
  int crntemp=0;
  printf("Remove Course\n");
  printf("Please enter the SID of the student: ");
  scanf("%s", ssidtemp);
  int ssid_loc=0, flag=0;
  for(ssid_loc=0; ssid_loc< count_stud; ssid_loc++)
  {
    if(!strcmp(students[ssid_loc].ssid, ssidtemp))
    {
      flag=1;
      break;
    }
  } //check if sid exists
  if(flag==0)
  {
    printf("NO SUCH SSID WAS FOUND.\n");
    return;
  }
  int i=0;
  printf("Current course: ");
  for(i=0;i<students[ssid_loc].count_classes;i++)
    printf("%d ", students[ssid_loc].crn[i]);
  printf("\n"); 
  printf("Please enter the CRN: ");
  scanf("%d", &crntemp);
  flag=0;
  for(i=0;i<students[ssid_loc].count_classes;i++)
  {
    if(students[ssid_loc].crn[i] == crntemp)
    {
      flag=1;
      break;
    }
  }
  if(flag == 0)
  {
    printf("You are not registered for this CRN.\n");
    return;
  }
  int j=0;
  for(j=i;j<students[ssid_loc].count_classes-1;j++)
  {
    students[ssid_loc].crn[j] = students[ssid_loc].crn[j+1];
  }
  students[ssid_loc].count_classes--;
  students[ssid_loc].crn[students[ssid_loc].count_classes]=0;
} //end rm_course
