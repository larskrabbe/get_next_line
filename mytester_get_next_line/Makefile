SRC =		../git_get_next_line/get_next_line.c\
			../git_get_next_line/get_next_line_utils.c

CFLAGS = -Werror -Wextra -Wall

CC = 		cc

all:hun

1000:
		@cc get_next_line_main.c $(SRC) -D BUFFERSIZE=42
		@./a.out
hun:
		@cc get_next_line_main.c $(SRC) -D BUFFERSIZE=10 -D TEST="100words.txt"
		@./a.out
clean:
		rm a.out

re: clean all

norm:
	norminette $(SRC)
.phony: re clean all 