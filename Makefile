SRC = srcs
FILES = srcs/additional_function.c \
		srcs/fractol.c \
		srcs/mandelbrot.c
CFLAGS = -Werror -Wextra -Wall
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
