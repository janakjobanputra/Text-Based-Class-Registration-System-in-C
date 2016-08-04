#ifndef RSVP_H
#define RSVP_H

typedef struct
{
  int crn;
  char subj[4];
  char course_no[5];
}Course;

typedef struct
{
  char* first;
  char* last;
  char ssid[15];
  int crn[6];
  int count_classes;
}Student;

#define SUBJECT 4
#define COURSE_NO 5
#define NAME 30
#define SSID 15

int get_choice();
void display_info(Course *courses, int count, Student *students, int count_stud);

#endif
