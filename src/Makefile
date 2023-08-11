CC	=	gcc -Wall -Wextra -Werror -std=c11

SRC	=	s21_is_less.c s21_is_greater.c s21_is_equal.c s21_is_not_equal.c \
		s21_is_greater_or_equal.c s21_is_less_or_equal.c \
		 s21_sub.c s21_add.c s21_mul.c  s21_div.c  s21_mod.c \
		 s21_truncate.c s21_floor.c s21_round.c s21_negate.c \
		s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_float_to_decimal.c \
		s21_from_int_to_decimal.c help.c

OBJ	=	$(SRC:%.c=%.o)

LIB =	s21_decimal.a

all: 	$(LIB) test

$(LIB):	$(OBJ)
		ar rc $(LIB) $^

%.o:	%.c s21_decimal.h
		$(CC) -c $<

test:
		$(CC) -lgcov -coverage test_decimal.c $(SRC) -lcheck -lm -lpthread -o test
		./test

lint:
		cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
		python3 ../materials/linters/cpplint.py --extensions=c *.c

gcov_report: test
		lcov -t "test" -o test.info -c -d .
		genhtml -o test_output test.info
		@cd ./test_output ; open index.html

clean:
		rm -rf $(OBJ) $(LIB)
		rm -rf *.gcno *.gcda ./test
		rm -rf ./test_output/ test.info
		rm -rf CPPLINT.cfg

re: clean all
