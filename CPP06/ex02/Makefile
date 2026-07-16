CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= program
SRC      = main.cpp identify.cpp
HEADERS  = Base.hpp A.hpp B.hpp C.hpp identify.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: clean all

PHONY: all clean re