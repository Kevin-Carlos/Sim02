# target executable name
TARGET = Sim02

# Compiler
CC=g++

# Compiler Flags
CXXFLAGS = -pthread -g -Wall -std=c++11

# Source files
SOURCES = ConfigData.cpp main.cpp MetaData.cpp Simulator.cpp

# header file dependencies
HEADERS = ConfigData.h MetaData.h Simulator.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

#default target
all: $(TARGET)

# link everything together
$(TARGET):	$(OBJECTS)
				$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJECTS):	$(SOURCES) $(HEADERS)
				$(CC) $(CXXFLAGS) -c $(SOURCES)

# Clean target
clean:
		rm $(TARGET) $(OBJECTS)