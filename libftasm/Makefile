NAME = libfts.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes/

SRC_D = ./srcs/

OBJS_D = ./objs/

SRCS = 	ft_isalpha.s \
		ft_isdigit.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_tolower.s \
		ft_toupper.s \
		ft_bzero.s \
		ft_strcat.s \
		ft_puts.s \
		ft_strlen.s \
		ft_memset.s \
		ft_memcpy.s \
		ft_strdup.s \
		ft_isprint.s

OBJS = $(SRCS:.s=.o)

SRC:=$(addprefix $(SRC_D), $(SRCS))
OBJ:=$(addprefix $(OBJS_D), $(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJS_D)%.o: $(SRC_D)%.s
	@mkdir -p $(OBJS_D)
	nasm -f macho64 $< -o $@

debug:
	$(CC) $(FLAGS) -c main.c $(INCLUDES) -o main.o
	ld main.o -L. -lfts -macosx_version_min 10.8 -lSystem -o test

clean:
	@rm -rf $(OBJS_D)

fclean: clean
	@rm -f $(NAME)
re: fclean all
