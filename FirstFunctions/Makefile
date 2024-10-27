
# Compilers and options
CC = g++
ASM = nasm
ASMFLAGS = -f elf64

#NAMES
LIBRARY = libmyasmlib.a
NAME = tester

ASM_SRC = func.s
ASM_OBJ = func.o
MAIN_SRC = main.cpp

all: $(NAME)

$(ASM_OBJ): $(ASM_SRC)
	$(ASM) $(ASMFLAGS) -o $(ASM_OBJ) $(ASM_SRC)

$(LIBRARY): $(ASM_OBJ)
	ar rcs $(LIBRARY) $(ASM_OBJ)

$(NAME): $(MAIN_SRC) $(LIBRARY)
	$(CC) -o $(NAME) $(MAIN_SRC) -L. -lmyasmlib

clean:
	rm -rf $(ASM_OBJ) $(LIBRARY)

fclean: clean
	rm -rf $(NAME)

re: fclean all