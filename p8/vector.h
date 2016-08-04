#ifndef VECTOR_H
#define VECTOR_H

void initialize(Course **courses, int *size);
void resize(Course **courses, int *size, int *count);
void deallocate(Course **courses, int *size, int *count);

#endif
