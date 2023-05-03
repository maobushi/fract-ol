CC = cc
CFLAGS = -Wall -Wextra -Werror 
S_NAME = server
SRCDIR = src
OBJDIR = obj
INCDIR = include
NAME = fractol

SRC = src/fractol.c
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:%.c=%.o)))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir obj

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(@) -c $(<)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM)r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all