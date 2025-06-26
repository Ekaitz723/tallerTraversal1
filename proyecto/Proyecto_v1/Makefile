CXX = g++
CXXFLAGS = -I./include -std=c++11 -O2
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Targets
all: Main tests_unitarios

Main: $(OBJECTS) Main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

tests_unitarios: $(OBJECTS) Test_Unitarios.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) Main tests_unitarios

.PHONY: all clean