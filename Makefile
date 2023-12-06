CXX := $(or $(shell echo $$CXX),g++)
CXXFLAGS := -Wall -Wextra -O3 -s -Iinclude $(shell sdl2-config --cflags --libs) $(shell echo $$CXXFLAGS)

SRC_DIR := src
OBJ_DIR := obj
TARGET := bin/classic-snake

SRC := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC)))

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(TARGET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$< -> $@"

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)/*
	@rm -f $(TARGET)

.PHONY: rebuild
rebuild: clean $(TARGET)

.PHONY: format
format:
	@clang-format -style=llvm -i src include

.PHONY: install
install: $(TARGET)
	@cp $(TARGET) /usr/local/bin
	@echo "$(TARGET) -> /usr/local/bin"
