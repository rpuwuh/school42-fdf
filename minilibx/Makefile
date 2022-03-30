ifeq ($(shell uname),Darwin)
    DIR=minilibx_macos/
else
    ifeq ($(OS),Linux)
		DIR=minilibx-linux/
	else
		echo "Cannot recognize your system\n"; exit 1
	endif
endif

libmlx.a: $(DIR)libmlx.a
	cp $(DIR)libmlx.a libmlx.a

$(DIR)libmlx.a:
	make -s -C $(DIR);

all: libmlx.a

clean:
	rm libmlx.a

fclean:
	make clean -C minilibx_macos/ ;
	make clean -C minilibx-linux/ ;
	rm libmlx.a

.PHONY: all clean fclean