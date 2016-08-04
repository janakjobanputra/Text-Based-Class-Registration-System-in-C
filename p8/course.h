#ifndef COURSE_H
#define COURSE_H

void read_courses(char* filename, Course **courses, int *size, int *count);
void find_CRN(Course *courses, int count, Student *students, int count_stud);
void find_subject(Course *courses, int count);

#endif
