CO = gcc -c
ALL = text.o option_1.o option_2.o option_3.o option_4.o
HEADERS = header/functions.h header/structures.h header/defines.h

all: main.o ${ALL}
	gcc main.o ${ALL} -o course_work

main.o: main.c ${HEADERS}
	${CO} main.c

text.o: text.c ${HEADERS}
	${CO} text.c

first_option.o: option_1.c ${HEADERS}
	${CO} first_option.c

second_option.o: option_1.c ${HEADERS}
	${CO} second_option.c

third_option.o: option_3.c ${HEADERS}
	${CO} third_option.c

fourth_option.o: option_4.c ${HEADERS}
	${CO} fourth_option.c



run: all
	./course_work

clean:
	rm -rf *.o course_work debugfile
