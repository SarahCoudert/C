
CC = gcc

NASM_PATH = nasm

SRC = 	ft_isalpha.s \
		ft_isdigit.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_tolower.s \
		ft_toupper.s

OBJ = $(SRC:.s=.o)

MAIN = main.c

EXE = test

CFLAGS = -Wall -Werror -Wextra

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -o $(EXE)

%.o: %.s
	$(NASM_PATH) -f macho64 $< -o $@

fclean : clean
	rm $(EXE)

clean :
	rm $(OBJ)

re : fclean all
