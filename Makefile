SRC = src
BIN = bin
NAME = ini_parser
EXAMPLES = examples

all:
	ragel -C $(SRC)/$(NAME).rl -o $(SRC)/$(NAME).c
	gcc $(SRC)/$(NAME).c -o $(BIN)/$(NAME)

run:
	./$(BIN)/$(NAME) $(EXAMPLES)/file.ini

clean_bin:
	rm - rf bin/*