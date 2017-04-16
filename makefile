#Credit to Stephen Lane-Walsh for his exemplary tutelage

.PHONY: all clean

SOURCES = $(wildcard *.cpp)
OUT = test

CXXFLAGS += -Wall -std=c++11 -msse -msse3

$(OUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SOURCES)

all: $(OUT)

clean:
	rm -f $(OUT)

run:
	./$(OUT)
