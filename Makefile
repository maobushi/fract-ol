CC = cc
CFLAGS = -Wall -Wextra -Werror 
S_NAME = server
SRCDIR = src
OBJDIR = obj
INCDIR = include
NAME = fractol

SRC = src/fractol.c
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:%.c=%.o)))

MLX        = miniLibX/
MLX_LNK    = -L $(MLX) -l mlx -framework OpenGL -framework AppKit
MLX_INC    = -I $(MLX)
MLX_LIB    = $(addprefix $(MLX),mlx.a)

all: $(OBJDIR) $(MLX_LIB) $(NAME)

$(OBJDIR):
	mkdir obj

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(@) -c $(<)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(MLX_LIB):
    @make -C $(MLX)

$(NAME): $(OBJ)
    $(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	$(RM)r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all