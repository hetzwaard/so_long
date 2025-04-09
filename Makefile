# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx42 -ldl -lglfw -pthread -lm
INCLUDES = -Iinclude
MLXFLAGS = $(LIBS) $(INCLUDES)

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = include
LIBFTDIR = include/libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = include/MLX42/build
MLX = $(MLXDIR)/libmlx42.a

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
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) $(LIBFT) $(MLXFLAGS) -o $(NAME)
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
	@echo "$(GRAY)Building MLX42..."
	@cmake -S include/MLX42 -B include/MLX42/build > /dev/null
	@cmake --build include/MLX42/build > /dev/null
	@echo "$(GREEN)MLX42 has been created successfully."

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