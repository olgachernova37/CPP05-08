CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= bureaucratt
SRC= main.cpp Bureaucrat.cpp AForm.cpp  ShrubberyCreationForm.cpp \
                RobotomyRequestForm.cpp \
                PresidentialPardonForm.cpp Intern.cpp
HEADERS= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
                RobotomyRequestForm.hpp \
                PresidentialPardonForm.hpp Intern.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: clean all

PHONY: all clean re