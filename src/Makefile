.PHONY: clean test my_string.a gcov_report
CC = gcc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname)
ifeq ($(OS),Darwin)
	CHECKFLAGS = -lcheck
else
	CHECKFLAGS = -lcheck -lpthread -lrt -lm -lsubunit
endif
all: my_string.a test gcov_report

my_string.a: clean
	clear
	$(CC) -c my_string.c -o my_string.o
	ar rc my_string.a my_string.o
	ranlib my_string.a

test: my_string.a
	$(CC) test.c my_string.a $(CHECKFLAGS) -o a.out
	./a.out

gcov_report: my_string.a
	$(CC) $(GCOVFLAGS) my_string.c test.c $(CHECKFLAGS) -o gcov_rep.out
	./gcov_rep.out
	lcov -t "gcov_rep" --output-file=coverag.info --capture --directory .
	genhtml -o ./report coverag.info
	open ./report/index.html

leaks: test
	CK_FORK=no leaks --atExit -- ./a.out

clean:
	clear
	rm -f *.o *.a *.gcno *.gcda *.info *.out
	rm -rf ./report
