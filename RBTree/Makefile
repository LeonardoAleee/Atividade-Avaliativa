# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = rbtree

# Source files
SRCS = main.cpp RBTree.cpp

# Header files
HEADERS = RBTree.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
