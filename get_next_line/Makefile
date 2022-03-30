NAME = get_next_line.a

SRC = get_next_line_utils_bonus.c  get_next_line_bonus.c
	  
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror


$(NAME): $(OBJ) get_next_line_bonus.h
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
