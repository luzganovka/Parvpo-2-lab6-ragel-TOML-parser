SRC = src
BIN = bin
OUT = out
NAME = ini_parser
EXAMPLE = examples/random.ini
MACHINES = main value key section
SIZES = 100 300 500 700 900 1100

init:
	@mkdir -p out
	sudo apt update
	@echo "\ninstalling packeges...\n"
	sudo apt install -y ragel build-essential graphviz xdg-utils

compile:
	ragel -C $(SRC)/$(NAME).rl -o $(SRC)/$(NAME).c
	gcc -DPRINT_OUTPUT $(SRC)/$(NAME).c -o $(BIN)/$(NAME)

run:
	$(BIN)/$(NAME) $(EXAMPLE)


timing:
	ragel -C $(SRC)/$(NAME).rl -o $(SRC)/$(NAME).c
	gcc $(SRC)/$(NAME).c -o $(BIN)/$(NAME)
	gcc $(SRC)/benchmark.c -o $(BIN)/benchmark -lrt
	$(BIN)/benchmark 200 1000


graph-all:
	@for m in $(MACHINES); do \
		echo "Generating SVG for $$m..."; \
		ragel -V	$(SRC)/$(NAME).rl	-o $(OUT)/$$m.dot -M $$m; \
		dot -Tsvg 	$(OUT)/$$m.dot		-o $(OUT)/$$m.svg; \
		rm			$(OUT)/$$m.dot; \
	done
	@echo "All SVGs saved as $(OUT)/<machine_name>.svg!"

	
clean_bin:
	rm - rf bin/*