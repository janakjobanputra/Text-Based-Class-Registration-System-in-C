rsvp.out: rsvp.o course.o vector.o student.o
	gcc -g -Wall -o rsvp.out rsvp.o course.o vector.o student.o

rsvp.o: rsvp.h course.h vector.h student.h rsvp.c
	gcc -g -c -Wall rsvp.c

course.o: rsvp.h course.h vector.h course.c
	gcc -g -c -Wall course.c

vector.o: rsvp.h vector.h vector.c
	gcc -g -c -Wall vector.c

student.o: rsvp.h student.h student.c
	gcc -g -c -Wall student.c

clean:
	rm -f vector.o course.o rsvp.o
