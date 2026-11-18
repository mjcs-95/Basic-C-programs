
# Compiler configuration
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -g
LDLIBS := -lm

# Directories
BIN_DIR := bin

# Automatically detect P*.c files
SOURCES := $(wildcard P*.c)
PROGRAMS := $(patsubst %.c,%,$(SOURCES))
TARGETS := $(addprefix $(BIN_DIR)/,$(PROGRAMS))

.DEFAULT_GOAL := all

.PHONY: all clean list help $(PROGRAMS)

# Build all programs
all: $(TARGETS)

# Create output directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile each program independently
$(BIN_DIR)/%: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

# Build a specific program: make P1
$(PROGRAMS): %: $(BIN_DIR)/%

# List available programs
list:
	@echo "Available programs: $(PROGRAMS)"

# Remove generated executables
clean:
	rm -rf $(BIN_DIR)

# Show available commands
help:
	@echo "Available commands:"
	@echo "  make        Build all programs"
	@echo "  make P1     Build P1"
	@echo "  make P2     Build P2"
	@echo "  make list   List available programs"
	@echo "  make clean  Remove generated files"
