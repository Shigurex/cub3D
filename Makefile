CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
LDFLAGS =  -Wshadow -Imlx
INCLUDES = -I ./includes

SRCDIR = srcs
OBJDIR = objs

LIBFT = libft/libft.a
MINILIBX = minilibx_mms_20200219/libmlx.dylib

SRC_NAME = main/main.c \
	setup/setup.c \
	setup/key.c \
	parse/readfile.c \
	parse/texture.c \
	parse/map.c \
	parse/convert.c \
	plot/action.c \
	plot/plot.c \
	plot/view.c \
	plot/minimap.c \
	plot/pixel_put.c \
	raycasting/raycasting.c \
	raycasting/raycasting_utils.c \
	utils/exit_error.c \
	utils/safe_free.c \
	utils/count.c \
	utils/list.c \
	utils/rgb_to_color.c \
	utils/degree_to_radian.c \
	utils/assign_pos.c \
	utils/get_sign.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NAME = cub3D

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ./minilibx_mms_20200219
	cp -f $(MINILIBX) ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) libmlx.dylib -o $(NAME)

$(OBJDIR):
	mkdir $(shell find $(SRCDIR) -type d | sed 's/^$(SRCDIR)/$(OBJDIR)/g')

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C ./minilibx_mms_20200219
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: all clean fclean re
