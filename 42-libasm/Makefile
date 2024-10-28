# Compilers and options
ASM 			= nasm
CXX				= c++
ASMFLAGS 		= -f elf64

# NAMES and DIRS
NAME 			= libasm.a
TESTERNAME		= tester
SRCSDIR			= srcs
OBJSDIR			= objs

# Source and object files
ASM_SRC 		= $(SRCSDIR)/ft_strlen.s $(SRCSDIR)/ft_strcpy.s
ASM_OBJ 		= $(ASM_SRC:$(SRCSDIR)/%.s=$(OBJSDIR)/%.o)

TESTERSRC		= tester.cpp

# Rules
all: $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.s | $(OBJSDIR)
	$(ASM) $(ASMFLAGS) -o $@ $<

$(NAME): $(ASM_OBJ)
	ar -rcs $(NAME) $(ASM_OBJ)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

tester:
	$(CXX) $(TESTERSRC) $(NAME) -o $(TESTERNAME)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME) $(TESTERNAME)

re: fclean all tester
