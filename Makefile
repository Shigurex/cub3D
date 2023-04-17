CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =  -Wshadow -Imlx
INCLUDES = -I ./includes

SRCDIR = srcs
OBJDIR = objs

LIBFT = libft.a
LIBFT_DIR = ./libft

MINILIBX = libmlx.dylib
MINILIBX_DIR = ./minilibx_mms_20200219

SRC_NAME = main/main.c \
	setup/setup.c \
	setup/init.c \
	setup/read.c \
	setup/key.c \
	setup/textures.c \
	setup/map.c \
	setup/convert.c \
	setup/convert_utils.c \
	plot/plot.c \
	plot/action.c \
	plot/minimap.c \
	plot/base.c \
	plot/arms.c \
	plot/pixel_put.c \
	raycasting/raycasting.c \
	raycasting/raycasting_utils.c \
	raycasting/door.c \
	utils/exit.c \
	utils/free.c \
	utils/color.c \
	utils/list.c \
	utils/string.c \
	utils/pos.c \
	utils/count.c \
	utils/sign.c \
	utils/angle.c \
	utils/solve_vector.c \
	utils/gaussian_elimination.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NAME = cub3D

$(NAME): $(OBJDIR) $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(MINILIBX) -o $(NAME)

$(OBJDIR):
	mkdir $(shell find $(SRCDIR) -type d | sed 's/^$(SRCDIR)/$(OBJDIR)/g')

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)
	cp -f $(MINILIBX_DIR)/$(MINILIBX) ./

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	$(RM) $(MINILIBX)
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: all clean fclean re
