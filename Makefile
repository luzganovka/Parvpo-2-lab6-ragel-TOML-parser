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
	gcc $(SRC)/$(NAME).c -o $(BIN)/$(NAME)

run:
	./$(BIN)/$(NAME) $(EXAMPLE)

graph-all:
	@for m in $(MACHINES); do \
		echo "Generating SVG for $$m..."; \
		ragel -V	$(SRC)/$(NAME).rl	-o $(OUT)/$$m.dot -M $$m; \
		dot -Tsvg 	$(OUT)/$$m.dot		-o $(OUT)/$$m.svg; \
		rm			$(OUT)/$$m.dot; \
	done
	@echo "All SVGs saved as $(OUT)/<machine_name>.svg!"

random_ini:
	python3 $(SRC)/ini_generator.py -z 100 -o $(EXAMPLE)

timing:
	@for size in $(SIZES); do \
		python3 $(SRC)/ini_generator.py -z $$size -o $(EXAMPLE); \
		make run; \
	done
	@echo "All iterations passed!"

	
clean_bin:
	rm - rf bin/*