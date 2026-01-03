# ----------------------------------------------------
# Universal C Makefile (Adjusted for 'code' folder)
# ----------------------------------------------------

CC = gcc
# -Ilib allows you to do #include "utils.h" easily
CFLAGS = -Wall -Wextra -Ilib

# 1. CHANGE THIS LINE: Point to your 'code' folder
SRC_DIR = code
LIB_DIR = lib
BUILD_DIR = build

# Default to day001 if no day is specified
day ?= day_1

# The source file is inside code/day_1.c + all files in lib/
SRCS = $(SRC_DIR)/$(day).c $(wildcard $(LIB_DIR)/*.c)
TARGET = $(BUILD_DIR)/$(day)

# ----------------------------------------------------

run: $(TARGET)
	@echo "----------------------------------------"
	@echo "🚀 Executing $(day)..."
	@echo "----------------------------------------"
	@./$(TARGET)

$(TARGET):
	@mkdir -p $(BUILD_DIR)
	@echo "🔨 Compiling $(day) and libraries..."
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	@echo "🧹 Cleaning up..."
	@rm -rf $(BUILD_DIR)