NAME = avm

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = 	./src/main.cpp \
    ./src/Parser.cpp \
	./src/Vm.cpp \
	./src/OperandFactory.cpp \
	./src/Int8operand.cpp \
	./src/Int16operand.cpp \
	./src/Int32operand.cpp \
	./src/FloatOperand.cpp \
	./src/DoubleOperand.cpp

OBJS =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.cpp.o:
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
