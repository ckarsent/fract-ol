NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Imlx -Iminilibx-linux -g3 -O3
MLXFLAGS = -Lminilibx-linux -lm -lmlx -lX11 -lXext

MINILIBX_DOSS = minilibx-linux
SRC_DIR = src
BONUS_DIR = bonus

MINILIBX = $(MINILIBX_DOSS)/libmlx.a

SRCS = ./src/main.c \
		./src/parsing.c \
		./src/utils.c \
		./src/window.c \
		./src/calculs_and_color.c \
		./src/mouse.c \
		./src/draw.c

SRCS_BONUS = ./bonus/main_bonus.c \
			./bonus/parsing_bonus.c \
			./bonus/utils_bonus.c \
			./bonus/window_bonus.c \
			./bonus/calculs_and_color_bonus.c \
			./bonus/draw_burningship_bonus.c \
			./bonus/mouse_bonus.c \
			./bonus/draw_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MINILIBX) -o $(NAME)

bonus: $(MINILIBX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(MINILIBX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(MINILIBX) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DOSS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(MINILIBX_DOSS) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(MINILIBX_DOSS) clean

re: fclean all

.PHONY: all bonus clean fclean re
