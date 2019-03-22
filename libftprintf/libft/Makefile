# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:30:07 by ade-verd          #+#    #+#              #
#    Updated: 2018/11/07 16:51:35 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

# Compiler
CC = gcc

INC_DIR = includes
SRC_DIR = ./

FT_MEM = \
		 ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		 ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_memccpy_src.c\
		 ft_swap.c

FT_STR = \
		 ft_strlen.c ft_strdup.c ft_strndup.c ft_strcpy.c ft_strncpy.c\
		 ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		 ft_strchr_pos.c ft_strrchr_pos.c ft_strstr.c ft_strleft.c\
		 ft_strright.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c\
		 ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
		 ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
		 ft_strnjoin.c ft_strnjoinfree.c ft_strtrim.c ft_strsplit.c\
		 ft_strmsplit.c ft_countwords.c get_next_line.c ft_stroffset.c

FT_CHAR = \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		  ft_toupper.c ft_tolower.c

FT_NUM = \
		 ft_abs.c ft_intlen.c ft_power.c ft_sqrt.c ft_int_sqrt.c\
		 ft_atoi.c ft_atoi_base.c ft_itoa.c ft_itoa_base.c\
		 ft_bitlen.c

FT_LST = \
		 ft_lstnew.c ft_lstadd.c ft_lstappend.c\
		 ft_lstdelone.c ft_lstdel.c\
		 ft_lstiter.c ft_lstmap.c

FT_DISPLAY = \
			 ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
			 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

FT_FD =	\
		ft_open_fd.c ft_close_fd.c ft_remove.c ft_file_exists.c

SRC = $(FT_MEM) $(FT_STR) $(FT_CHAR) $(FT_NUM) $(FT_LST) $(FT_DISPLAY)\
	  $(FT_FD)

OBJ_PATH = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags with OS Compatibiliy
OS = $(shell uname)
ifeq ($(OS), Darwin)
	FLAGS_DEFAULT = -Werror -Wall -Wextra
endif
ifeq ($(OS), Linux)
	FLAGS_DEFAULT = -Wno-unused-result
endif
ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS := $(ADDFLAGS)
	endif
#	ifeq ($(FLAGS), debug)
#		CFLAGS := $(FLAGS_DEFAULT) -ansi -pedantic -g $(ADDFLAGS)
#	endif
else
	CFLAGS := $(FLAGS_DEFAULT) $(ADDFLAGS)
endif

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

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): obj $(OBJ)
	@if [ $(COUNTER) -ne 0 ]; then \
		echo -e $(EMPTY_LINE)"$(LOG_UP)$(LOG_NOCOLOR) $(COUNTER) file(s) linked"; \
		ar -rc $(NAME) $(OBJ) && echo -e $(ASSEMBLING); \
		ranlib $(NAME) && echo -e $(INDEXING); \
	fi;

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(BUILD_NUMBER_LDFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo -e $(EMPTY_LINE)"$(LOG_UP) $<              "
	$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

obj:
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@mkdir -p $(OBJ_PATH)
	@echo -e $(LINKING)

clean:
	@echo -e "$(TITLE)clean libft $(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)

fclean:
	@echo -e "$(TITLE)fclean libft $(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)

clean_quiet:
	@rm -Rf $(OBJ_PATH)

fclean_quiet: clean_quiet
	@rm -f $(NAME)

re: fclean all
