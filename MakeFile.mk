CFLAGS = -Wall -Wextra -g -std=c11

BUILD = build
SRC = src
INCLUDE = include

all: $(BUILD)/main

$(BUILD)/main: $(BUILD)/main.o $(BUILD)/get_system_info.o
	gcc $(CFLAGS) $(BUILD)/main.o -o $(BUILD)/main

$(BUILD)/main.o: $(SRC)/main.c | $(BUILD)
	gcc $(CFLAGS) -c $(SRC)/main.c -o $(BUILD)/main.o

$(BUILD)/get_system_info.o: $(INCLUDE)/get_system_info.c | $(BUILD)
	gcc $(CFLAGS) -c $(SRC)/get_system_info.c -o $(BUILD)/get_system_info.o

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) 