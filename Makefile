# Makefile for 3D Maze Game

# Compiler settings
CC = gcc
CFLAGS = -std=c99 -Wall -O2
INCLUDES = -I/c/msys64/ucrt64/include
LDFLAGS = -L/c/msys64/ucrt64/lib
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
TARGET = maze_game.exe
SOURCES = $(SRC_DIR)/main.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCES)
	@echo "Building 3D Maze Game..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(SOURCES) $(LDFLAGS) $(LIBS)
	@echo "Build complete: $(TARGET)"

# Run the game
run: $(TARGET)
	@echo "Running 3D Maze Game..."
	./$(TARGET)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	@if exist $(TARGET) del $(TARGET)
	@echo "Clean complete."

# Help
help:
	@echo "3D Maze Game Makefile"
	@echo "====================="
	@echo "Available targets:"
	@echo "  make all   - Build the game (default)"
	@echo "  make run   - Build and run the game"
	@echo "  make clean - Remove build artifacts"
	@echo "  make help  - Show this help message"

.PHONY: all run clean help
