CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
INCLUDES = -I ./includes

SRCDIR = srcs
OBJDIR = objs

LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Darwin.a

SRC_NAME = main/main.c \
	setup/setup.c \
	setup/key.c \
	parse/readfile.c \
	parse/texture.c \
	parse/map.c \
	parse/convert.c \
	plot/action.c \
	plot/plot.c \
	plot/minimap.c \
	plot/pixel_put.c \
	raycasting/raycasting.c \
	utils/exit_error.c \
	utils/safe_free.c \
	utils/count.c \
	utils/list.c \
	utils/rgb_to_color.c \
	utils/degree_to_radian.c \
	utils/assign_pos.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NAME = cub3D

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)

$(OBJDIR):
	mkdir $(shell find $(SRCDIR) -type d | sed 's/^$(SRCDIR)/$(OBJDIR)/g')

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C ./minilibx-linux
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: all clean fclean re
