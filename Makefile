# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -L/usr/lib/X11 -lXext -lX11

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = include
LIBFTDIR = include/libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = include/mlx
MLX = $(MLXDIR)/libmlx.a

# Source files and object files
SRCS = $(SRCDIR)/main.c \

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Output executable
NAME = so_long

# Colors for output
GREEN		=	\033[0;32m
ORANGE	=	\033[38;5;214m
GRAY		=	\033[0;90m

# Rules
all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS)
	@echo "$(GRAY)Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created successfully."

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(GRAY)Compiling $<..."
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR) -c $< -o $@

$(LIBFT):
	@echo "$(GRAY)Building Libft..."
	@make -C $(LIBFTDIR) > /dev/null
	@echo "$(GREEN)Libft has been created successfully."

$(MLX):
	@echo "$(GRAY)Building MiniLibX..."
	@make -C $(MLXDIR) > /dev/null
	@echo "$(GREEN)MiniLibX has been created successfully."

clean:
	@echo "$(ORANGE)Cleaning object files..."
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean > /dev/null
	@make -C $(MLXDIR) clean > /dev/null
	@echo "$(ORANGE)Objects have been removed."

fclean: clean
	@echo "$(ORANGE)Removing $(NAME)..."
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean > /dev/null
	@make -C $(MLXDIR) clean > /dev/null
	@echo "$(ORANGE)$(NAME) has been removed."

re: fclean all

.PHONY: all clean fclean re