# Compilers and options
ASM 			= nasm
CC				= cc
ASMFLAGS 		= -f elf64
CFLAGS			= -Wall -Werror -Wextra

# NAMES and DIRS
NAME 			= libasm.a
TESTERNAME		= tester
SRCSDIR			= srcs
OBJSDIR			= objs

# Source and object files
ASM_SRC 		= $(SRCSDIR)/ft_strlen.s \
				  $(SRCSDIR)/ft_strcpy.s \
				  $(SRCSDIR)/ft_strcmp.s \
				  $(SRCSDIR)/ft_write.s  \
				  $(SRCSDIR)/ft_read.s   \
				  $(SRCSDIR)/ft_strdup.s \
				  $(SRCSDIR)/ft_list_size_bonus.s \
				  $(SRCSDIR)/ft_list_push_front_bonus.s \



ASM_OBJ 		= $(ASM_SRC:$(SRCSDIR)/%.s=$(OBJSDIR)/%.o)

TESTERSRC		= tester.c

# Rules
all: $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.s | $(OBJSDIR)
	$(ASM) $(ASMFLAGS) -o $@ $<

$(NAME): $(ASM_OBJ)
	ar -rcs $(NAME) $(ASM_OBJ)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

tester:
	$(CC) $(CFLAGS) $(TESTERSRC) $(NAME) -o $(TESTERNAME) -g

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME) $(TESTERNAME)

re: fclean all tester
