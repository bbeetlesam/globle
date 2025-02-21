# Compiler
CC = g++
CFLAGS = -Wall -Wextra -g -I./include -I./lib

# Direktori
BIN_DIR = bin
OBJ_DIR = lib/obj

# File source dan object
SRCS = src/main.cpp src/utils.cpp src/countries.cpp src/save.cpp scenes/menu/menu.cpp scenes/menu/collections.cpp scenes/menu/statistics.cpp scenes/game/game_manager.cpp scenes/game/quick_mode.cpp scenes/game/regional_mode.cpp scenes/game/streak_mode.cpp
OBJS = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

# File header
HEADERS = include/main.hpp include/save.hpp

# Output binary
TARGET = $(BIN_DIR)/main.exe

# Rules
all: $(TARGET)

# Buat file binary (main.exe)
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile setiap file source menjadi file .o di lib/obj
$(OBJ_DIR)/%.o: src/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)/scenes
	$(CC) $(CFLAGS) -c $< -o $@

# Jalankan program
run: $(TARGET)
	./$(TARGET)

# Bersihkan file hasil kompilasi
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# for dbebugging
frun:
	./$(TARGET)

#############
test:
	$(CC) -o bin/TEST.exe src/TEST.cpp
	./bin/TEST
