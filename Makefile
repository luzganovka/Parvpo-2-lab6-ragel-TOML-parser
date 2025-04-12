SRC = src
BIN = bin
NAME = ini_parser

all:
	ragel -C $(SRC)/$(NAME).rl -o $(SRC)/$(NAME).c
	gcc $(SRC)/$(NAME).c -o $(BIN)/$(NAME)

run:
	./$(BIN)/$(NAME)

clean_bin:
	rm - rf bin/*