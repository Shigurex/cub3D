CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
INCLUDES = -I ./includes

SRCDIR = srcs
OBJDIR = objs

LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Darwin.a

SRC_NAME = main.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NAME = cub3D

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)

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
