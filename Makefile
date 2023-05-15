# CC = cc
# CFLAGS = -Wall -Wextra -Werror 
# S_NAME = server
# SRCDIR = src
# OBJDIR = obj
# INCDIR = include
# NAME = fractol

# SRC = src/fractol.c src/additional_function.c src/mandelbrot.c
# OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:%.c=%.o)))

# MLX        = miniLibX
# MLX_LNK = -L $(MLX) -l mlx -lX11 -lXext -framework OpenGL -framework AppKit
# MLX_INC    = -I $(MLX)
# MLX_LIB    = $(addprefix $(MLX)/,libmlx.a)

# XFLAGS = -I /usr/local/include $(MLX_LIB) -framework OpenGL -framework AppKit

# all: $(OBJDIR) $(MLX_LIB) $(NAME)

# $(OBJDIR):
# 	mkdir obj

# $(OBJDIR)/%.o: $(SRCDIR)/%.c
# 	$(CC) $(CFLAGS) -I $(INCDIR) -o $(@) -c $(<)

# $(MLX_LIB):
# 	@make -C $(MLX)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -o $(@) $(XFLAGS) -L/usr/X11R6/lib -lX11 -lXext
# clean:
# 	$(RM)r $(OBJDIR)

# fclean: clean
# 	$(RM) $(NAME)
# 	make -C $(MLX) clean 

# re: fclean all

SRC = srcs
FILES = srcs/additional_function.c srcs/fractol.c srcs/mandelbrot.c
CFLAGS = -Werror -Wextra -Wall
#XFLAGS = -I /usr/local/include -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(FILES:.c=.o)
OBJDIR = obj
NAME = fractol
HEADER = include
CC = cc
RM = rm -f
UNAME = $(shell uname -s)
ifeq ($(UNAME),Linux)
	XFLAGS = -I /usr/local/include -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
	XFLAGS = -I /usr/local/include -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $@ $(XFLAGS)

$(SRC)/%.o: $(SRC)/%.c $(HEADER)/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

bonus: all

startall:
	$(shell ./fractol Mandelbrot & ./fractol Julia)

clean:
	$(RM) -r $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, startall, bonus
