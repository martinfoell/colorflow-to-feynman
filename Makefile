# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable name
TARGET = $(BIN_DIR)/main

# Include directories
INC_FLAGS = -I$(INC_DIR)

# Default target
all: $(TARGET)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Create directories if they don't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $^ -o $@

# Clean build artifacts
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean

