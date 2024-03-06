# Makefile section

# Compiler
CXX = g++

# Directories
SRCDIR = src
BUILDDIR = build

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Compiler flags (to be adjusted...)
CXXFLAGS = -std=c++11 -Wall -I/../../resources/sdl/SDL/include

# Linker flags (to be adjusted...)
LDFLAGS = -L/usr/local/lib -lSDL2

# Executable file
TARGET = program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)
