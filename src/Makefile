CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra -std=c11
OFLAGS = -Wall -Werror -Wextra -std=c11 -fprofile-arcs -ftest-coverage
LFLAGS = -lcheck -lsubunit -lm -lpthread -lrt
LIB_NAME = my_string.a

SRC_TEST = test_string.c

SRC_SSCANF = my_sscanf.c
SRC_SPECIFIERS = my_sscanf_specifiers.c
SSCANF_HEADER = my_sscanf.h

SRC_SPRINTF = my_sprintf.c
SRC_INSERTER = my_sprintf_inserter.c
SRC_CASES = my_sprintf_cases.c
SPRINTF_HEADER = my_sprintf.h

SRC_STRING = my_string.c
STRING_HEADER = my_string.h

OBJ_MAIN = $(SRC_SPRINTF:.c=.o)
OBJ_INSERTER = $(SRC_INSERTER:.c=.o)
OBJ_CASES = $(SRC_CASES:.c=.o)

OBJ_STRING = $(SRC_STRING:.c=.o)

OBJ_SSCANF = $(SRC_SSCANF:.c=.o)
OBJ_SPECIFIERS = $(SRC_SPECIFIERS:.c=.o)

.PHONY = all clean rebuild gcov_report test

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_MAIN) $(OBJ_CASES) $(OBJ_INSERTER) $(OBJ_STRING) $(OBJ_SSCANF) $(OBJ_SPECIFIERS)
	$(AR) rcs $@ $^

%.o: %.c $(SPRINTF_HEADER) $(STRING_HEADER) $(SSCANF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(SRC_TEST) $(LIB_NAME)
	mkdir -p lcovr
	gcc $(OFLAGS) $(SRC_TEST) $(LIB_NAME) -o test $(LFLAGS)
	./test
	cp *.gcno lcovr
	cp *.gcda lcovr

gcov_report: test
	cd lcovr; lcov -c -d .. -o my.info; genhtml -o results/ my.info;
	rm -f *.gcda *.gcno

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch lcovr a.out test

rebuild: clean all