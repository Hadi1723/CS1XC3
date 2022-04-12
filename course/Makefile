CC=gcc

all: main doxygen

main: course.o student.o

course.o: student.o

doxygen:
	doxygen Doxyfile

clean:
	rm -f -r *.o main

