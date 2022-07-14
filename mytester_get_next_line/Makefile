SRC =		../get_next_line.c\
			../get_next_line_utils.c

CFLAGS = -Werror -Wextra -Wall

CC = 		cc
# #-g -fsanitize=address
all:hun

1000:
		@cc get_next_line_main.c $(SRC) -D BUFFERSIZE=42
		@./a.out
hun:
		@cc get_next_line_main.c $(SRC) -D BUFFERSIZE=1 -D TEST="100words.txt" #-g -fsanitize=address
		@./a.out
big:
		@cc get_next_line_main.c $(SRC) -D BUFFERSIZE=42 -D FILENAME="big_line_no_nl"
		@./a.out
clean:
		rm a.out

re: clean all

norm:
	norminette $(SRC)
.phony: re clean all 