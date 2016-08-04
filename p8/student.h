#ifndef STUDENT_H
#define STUDENT_H

void initialize_stud(Student **students, int *size_stud);
void resize_stud(Student **students, int *size_stud, int *count_stud);
void deallocate_stud(Student **students, int *size_stud, int *count_stud);
void read_students(char* filename_stud, Student **students, int *size_stud,
  int *count_stud);
void add_course(Student *students, int count_stud, Course *courses, int count);
void rm_course(Student *students, int count_stud, Course *courses, int count);

#endif
