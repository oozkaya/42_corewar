# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2018/07/29 20:08:29 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = libftprintf.a

# Compiler
CC = gcc

# Directories
SRC_PATH = src/
OBJ_PATH = obj/
LIB_PATH = libft
INC_PATH = includes \
		   $(LIB_PATH)/includes
H_FILES = $(addprefix $(INC_PATH), /*.h) 

# Includes & libraries
CPPFLAGS = $(addprefix -I, $(INC_PATH))
LDFLAGS = -Llibft
LDLIBS = -lft
LIBFT = $(LIB_PATH)/libft.a

# Sources
SRC_NAME = \
		   a0_ft_printf.c\
		   a1_ft_vprintf.c\
		   b0_parser.c\
		   c0_struct_manager.c\
		   c1_get_chars_to_convert.c\
		   c2_printer.c\
		   c3_error_manager.c\
		   c4_unicode_converter.c\
		   c5_capital_type.c\
		   \
		   d0_arg_int.c\
		   d1_arg_char.c\
		   d2_arg_novalid_conv.c\
		   d3_arg_string.c\
		   \
		   e0_size_manager.c\
		   e1_indicators_manager.c\
		   e2_flags_manager_part1.c\
		   e3_flags_manager_part2.c\
		   e4_precision_manager.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags with OS Compatibiliy
OS = $(shell uname)
ifeq ($(OS), Darwin)
	FLAGS_DEFAULT += -Werror -Wall -Wextra
endif
ifeq ($(OS), Linux)
	FLAGS_DEFAULT += -Wno-unused-result
endif
ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS := $(ADDFLAGS)
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS := $(FLAGS_DEFAULT) -ansi -pedantic -g $(ADDFLAGS)
	endif
else
	CFLAGS := $(FLAGS_DEFAULT) $(ADDFLAGS)
endif

# MAKEFLAGS
MAKE = make --no-print-directory -C #$(MAKEFLAGS)

# Variables
COUNTER=0

# **************************************************************************** #
# SPECIALS CHARS                                                               #
# **************************************************************************** #
LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BOLD = \033[1m
LOG_UNDERLINE = \033[4m
LOG_BLINKING = \033[5m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

TITLE = $(LOG_CLEAR)$(LOG_BLUE)
END_TITLE = $(LOG_NOCOLOR)
LINKING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tlinking " \
				".................... $(LOG_VIOLET)" #$<$(LOG_NOCOLOR)"
EMPTY_LINE = "--$(LOG_CLEAR)$(LOG_VIOLET)\t                           "
ASSEMBLING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tassembling " \
			 	"............... $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
INDEXING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tindexing " \
			 	"................. $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
OBJECTS_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion " \
				"............ $(LOG_RED)×$(LOG_NOCOLOR)"
BIN_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion " \
				"............. $(LOG_RED)×$(LOG_NOCOLOR)"

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #
.PHONY: all, clean, fclean, re, norme, normadev

all: $(NAME)

$(NAME): libft.a $(OBJ_PATH) $(OBJ)
	@if [ $(COUNTER) -ne 0 ]; then \
		echo -e $(EMPTY_LINE)"$(LOG_UP)$(LOG_NOCOLOR) $(COUNTER) file(s) linked         "; \
		make libtool_link; \
		ranlib $(NAME) && echo -e $(INDEXING); \
	fi;
#	@ar -t $(NAME) # list library's functions

libft.a:
	@$(MAKE) $(LIB_PATH) $@

libtool_link: $(LIBFT) $(OBJ)
	@if [ $(OS) = Darwin ]; then \
		libtool -static -o $(NAME) $(OBJ) $(LIBFT) && echo -e $(ASSEMBLING); \
	fi;
	@if [ $(OS) = Linux ]; then \
		cp $(LIBFT) $(NAME) && ar rc $(NAME) $(OBJ) && echo -e $(ASSEMBLING); \
	fi;
#		ar rc $(NAME) $(LIBFT) && ar rc $(NAME) $(OBJ) && echo -e $(ASSEMBLING); \

$(OBJ_PATH):
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@echo -e "--$(LOG_CLEAR)Flags : $(CFLAGS)"
	@echo -e $(LINKING)
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(ADDFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -e $(EMPTY_LINE)"$(LOG_UP) $<              "
	$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

clean:
	@echo -e "$(TITLE)clean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e "$(TITLE)clean libft$(END_TITLE)"
	@$(MAKE) $(LIB_PATH) clean

fclean:
	@echo -e "$(TITLE)fclean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)
	@echo -e "$(TITLE)fclean libft$(END_TITLE)"
	@$(MAKE) $(LIB_PATH) fclean

re: fclean all

clean_quiet:
	@rm -Rf $(OBJ_PATH)
	@$(MAKE) $(LIB_PATH) clean_quiet

fclean_quiet: clean_quiet
	@rm -f $(NAME)
	@$(MAKE) $(LIB_PATH) fclean_quiet

norme:
	norminette $(SRC)
	norminette $(addprefix $(INC_PATH), /*.h)

normadev: 
	norminette **/*.[ch] | grep -B 1 "Error\|Warning" || echo "norme OK"
#	@echo ___
#	@sh ~/Projects/support/Normadev/normadev.sh $(SRC) $(H_FILES)

# Submodules
init_submodule:
	git submodule update --init --recursive

update_submodule:
	git submodule update --recursive --remote

# **************************************************************************** #
# Personal notes :                                                             #
#                                                                              #
# $@ : rule's name                                                             #
# $^ : all dependencies after ':'                                              #
# $< : corresponding dependency                                                #
# || : of there is an error, execute the command after the double pipe         #
#                                                                              #
# **************************************************************************** #
