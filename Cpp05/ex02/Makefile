CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= bureaucratt
SRC= main.cpp Bureaucrat.cpp Form.cpp
HEADERS= Bureaucrat.hpp Form.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: clean all

PHONY: all clean re