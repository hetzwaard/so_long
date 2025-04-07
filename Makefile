# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = include
LIBFTDIR = include/libft
LIBFT = $(LIBFTDIR)/libft.a

# Source files and object files
SRCS =	

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Output executable
NAME = so_long

# Colors for output
GREEN		=	\033[0;32m
ORANGE	=	\033[38;5;214m
GRAY		=	\033[0;90m

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) -L$(LIBFTDIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created."

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@
	@echo "$(GRAY)Compiled: $<"

$(LIBFT):
	@make -C $(LIBFTDIR)
	@echo "$(GREEN)Libft has been created."

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@echo "$(ORANGE)Objects have been removed."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "$(ORANGE)$(NAME) has been removed."

re: fclean all

.PHONY: all clean fclean re