# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 19:25:20 by anthtorr          #+#    #+#              #
#    Updated: 2023/12/22 16:31:53 by anthtorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for test_get_next_line

# Compiler
CC = cc

# Common compiler flags
CFLAGS_COMMON = -g -Wall -Wextra -Werror

# File containing the previous BUFFER_SIZE
SIZE_FILE = size.txt

# Read previous BUFFER_SIZE value
PREVIOUS_SIZE = $(shell cat $(SIZE_FILE))

# Set compiler flags based on BUFFER_SIZE, default to CFLAGS_COMMON
ifeq ($(SIZE),)
        CFLAGS = $(CFLAGS_COMMON)
else
        CFLAGS = $(CFLAGS_COMMON) -D BUFFER_SIZE=$(SIZE)
endif

# Include directories
INCLUDES = -I../

# Source files
SRCS = test_get_next_line.c \
           ../get_next_line.c \
           ../get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
NAME = test_get_next_line

# Default target
all: $(NAME)

# Check if BUFFER_SIZE has changed, if so, rebuild
ifeq ($(SIZE),$(PREVIOUS_SIZE))
else
        @echo "Size changed"
        @echo $(SIZE) > $(SIZE_FILE)
        @make re
endif

# Link object files to create executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile each source file to create object files
%.o: %.c $(SIZE_FILE) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Remove object files and target executable
clean:
	rm -f *.o
	rm -f ../*.o
	rm -f *.gch

# Remove object files, dependencies, and target executable
fclean: clean
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

# Run norminette on source files
norma: $(SRCS)
	norminette $(SRCS)

# Declare .PHONY targets to avoid conflicts with files
.PHONY: all clean fclean re norma

