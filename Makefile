SRCDIR = src
OBJSDIR = build
INCLUDESDIR = include
TESTDIR = tests

SOURCES = arghandler.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = commandlinelab

CXX = g++
CXXFLAGS = -Wall -g -I$(INCLUDESDIR)

all: directories commandlinelab

directories:
	mkdir -p $(OBJSDIR)

# Create the program binary
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o commandlinelab \
			$(OBJSDIR)/*.o

# Compile rules for each dependecy
main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJSDIR)/main.o $(SRCDIR)/main.cpp

arghandler.o: $(SRCDIR)/arghandler.cpp $(SRCDIR)/arghandler.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJSDIR)/arghandler.o $(SRCDIR)/arghandler.cpp


# Make the test_runner
test: $(TESTDIR)/test_arghandler.cpp
	$(CXX) $(CXXFLAGS) -Isrc/ -o test_runner $(TESTDIR)/test_*.cpp

# Rule to clean up intermediate file and executable
clean:
	rm -rf $(OBJSDIR)
	rm -f commandlinelab test_runner *.o
	
