NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_strlen.c\
	  ft_memset.c ft_bzero.c ft_memcpy.c\
	  ft_memmove.c ft_toupper.c ft_tolower.c\
	  ft_strchr.c ft_strrchr.c ft_strncmp.c\
	  ft_memchr.c ft_memcmp.c ft_strnstr.c\
	  ft_atoi.c ft_substr.c ft_strdup.c\
	  ft_calloc.c ft_strjoin.c ft_strtrim.c\
	  ft_split.c ft_itoa.c ft_strmapi.c\
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c\
	  ft_strlcat.c
	  
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
	  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	  ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_A = $(SRC) $(BONUS)

OBJ = $(SRC:.c=.o)

OBJ_B = $(BONUS:.c=.o)

OBJ_A = $(SRC_A:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar rcs $(NAME) $(OBJ)
 
clean:
	rm -f $(OBJ_A)
fclean: clean
	rm -f $(NAME)

bonus: $(OBJ_A)
	@make OBJ="$(OBJ_A)" SRC="$(SRC_A)" all
	

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
