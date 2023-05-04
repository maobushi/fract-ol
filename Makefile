CC = cc
CFLAGS = -Wall -Wextra -Werror 
S_NAME = server
SRCDIR = src
OBJDIR = obj
INCDIR = include
NAME = fractol

SRC = src/fractol.c
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:%.c=%.o)))

MLX        = miniLibX
MLX_LNK = -L $(MLX) -l mlx -lX11 -lXext -framework OpenGL -framework AppKit
MLX_INC    = -I $(MLX)
MLX_LIB    = $(addprefix $(MLX)/,libmlx.a)

XFLAGS = -I /usr/local/include $(MLX_LIB) -framework OpenGL -framework AppKit

all: $(OBJDIR) $(MLX_LIB) $(NAME)

$(OBJDIR):
	mkdir obj

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(@) -c $(<)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(@) $(XFLAGS) -L/usr/X11R6/lib -lX11 -lXext
clean:
	$(RM)r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	make -C $(MLX) clean 

re: fclean all