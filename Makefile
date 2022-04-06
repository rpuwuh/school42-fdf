NAME = fdf

OBJDIR= ./obj/

HEADER = fdf.h

SRC = fdf_atoi_hex.c fdf_checkfile.c fdf_mallocandset.c fdf_free.c fdf_mlx_funcs.c \
	fdf_bresenham.c fdf_draw.c

SRC_O = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = $(addprefix $(OBJDIR),libft.a)

GNL = $(addprefix $(OBJDIR),get_next_line.a)

MLX = $(addprefix $(OBJDIR),libmlx.a)

LIBS = $(LIBFT) $(GNL) $(MLX)

CC = cc

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJDIR) $(LIBFT) $(GNL) $(MLX) $(OBJDIR)$(NAME).o $(SRC_O) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(LIBS) $(SRC_O) $(OBJDIR)$(NAME).o -o $(NAME) -framework OpenGL -framework AppKit

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBFT): libft/*.c libft/*.h
	make -sC ./libft/; cp ./libft/libft.a $(OBJDIR)libft.a; make fclean -C ./libft;

$(GNL): get_next_line/*.c get_next_line/*.h
	make -sC ./get_next_line/; cp ./get_next_line/get_next_line.a $(OBJDIR)get_next_line.a;
	make fclean -C ./get_next_line;

$(MLX): 
	make -sC minilibx; cp minilibx/libmlx.a $(OBJDIR)libmlx.a

$(OBJDIR)$(NAME).o: $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJDIR)%.o: %.c $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

all: $(NAME) $(NAME_CHECKER)

exec: all clean

clean: 
	rm -f $(LIBFT) $(GNL) $(SRC_O) $(OBJDIR)$(NAME).o minilibx/mlx.h

fclean: clean
	rm -f $(NAME); rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re exec
