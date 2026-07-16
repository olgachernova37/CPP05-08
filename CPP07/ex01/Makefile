CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= program
SRC      = main.cpp 
HEADERS  = realiseIter.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: clean all

PHONY: all clean re