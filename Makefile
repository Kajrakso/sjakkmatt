# Compiler and standard flags
CC = g++
CFLAGS_COMMON = -std=c++23 -Wall -Wextra -Wconversion -Wno-unused-parameter -Wno-unused-function
CFLAGS_OPTIMIZED = -O3
CFLAGS_DEBUG = -g3 -fsanitize=address -fsanitize=undefined -fsanitize=leak

# Directories
SRC_DIR = src
TEST_DIR = test

# lichess bot
LICHESS_BOT_DIR = lichess-bot
LICHESS_BOT_SETUP_SCRIPT = lichess-bot-setup.sh

SRCS = $(shell find $(SRC_DIR) -name '*.cpp' -and -not -name 'main.cpp')
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
EXE = sjakkmatt

TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_EXE = test.out

# Default target
all: CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_OPTIMIZED)
all: $(EXE)

# Debug target
debug: CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_DEBUG)
debug: $(EXE)

# Test target
test: CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_DEBUG)
test: $(TEST_EXE)

# Compile the executable
$(EXE): $(OBJS) $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) $^ -o $@

# Test executable
$(TEST_EXE): $(TEST_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $^ -lcriterion -o $@ && ./$(TEST_EXE) --verbose=1

# Compile source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(EXE) $(TEST_OBJ) $(TEST_EXE)

# Setup the lichess bot
lichess-bot: $(EXE)
	if [ ! -d $(LICHESS_BOT_DIR) ]; then $(LICHESS_BOT_SETUP_SCRIPT); fi
	cp -f $(EXE) $(LICHESS_BOT_DIR)/engines/$(EXE)
	sed -i "s/name: \"engine_name\"/name: \"$(EXE)\"/" $(LICHESS_BOT_DIR)/config.yml

# Run the lichess bot
run-bot:
	cd $(LICHESS_BOT_DIR) && source venv/bin/activate && python3 lichess-bot.py -u

# Phony targets
.PHONY: all debug test clean lichess-bot run-bot
