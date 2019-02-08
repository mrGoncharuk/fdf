NAME = fdf

HEADER = fdf.h

SRCS = 	main.c \
		draw_net.c \
		draw_line.c \
		put_to_img.c \
		read_chords.c \
		get_next_line.c \
		rotator.c


OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a


FLAGS = -Wall -Werror -Wextra

.NOTPARALLEL: all clean fclean re

.PHONY: all clean fclean re

all: $(NAME)

start: all
	./fdf

$(NAME): $(LIBFT) $(OBJS)
	@cc $(FLAGS) -o $(NAME) -I /usr/local/include $(SRCS) $(LIBFT) -L /usr/local/lib -lmlx -framework openGL -framework AppKit

%.o: %.c $(HEADER)
	gcc -c $< -o $@ $(FLAGS)

$(LIBFT):
	make -C ./libft

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all