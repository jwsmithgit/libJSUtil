# Project Name
TARGET = jsutil

# Directories
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Compiler Flags
CC = g++
CFLAGS += -I $(INC_DIR)

# Sources
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Objects
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CFLAGS) -c $< -o $@

# Link
$(TARGET): $(OBJS)
	ar rcs $(TARGET).a $(OBJS)

# Clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET).a