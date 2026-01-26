CFLAGS = -Wall -Wextra -g -std=c11

BUILD = build
SRC = src

all: $(BUILD)/main

$(BUILD)/main: $(BUILD)/main.o
	gcc $(CFLAGS) $(BUILD)/main.o -o $(BUILD)/main

$(BUILD)/main.o: $(SRC)/main.c | $(BUILD)
	gcc $(CFLAGS) -c $(SRC)/main.c -o $(BUILD)/main.o

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) 