NAME = test

SRC	=	AtmosphereRegulator.cpp		
		Engine.cpp			
		Errors.cpp		
		Oxygenator.cpp			
		RoverUnitTests.cpp		
		WaterReclaimer.cpp
OBJ = $(SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -W -Wall -Wextra -std=c++14 -g
LDFLAGS =

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
