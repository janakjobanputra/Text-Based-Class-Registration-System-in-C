rsvp.out: rsvp.o course.o vector.o
	gcc -g -Wall -o rsvp.out rsvp.o course.o vector.o

rsvp.o: rsvp.h course.h vector.h rsvp.c
	gcc -g -c -Wall rsvp.c

course.o: rsvp.h course.h vector.h course.c
	gcc -g -c -Wall course.c

vector.o: vector.h vector.c
	gcc -g -c -Wall vector.c

clean:
	rm -f vector.o course.o rsvp.o
