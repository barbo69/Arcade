 ##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile Lib Ncurses
##

SRC				=	src/ArcadeNcurses/ArcadeNcurses.cpp\
					src/ArcadeNcurses/LibManagement.cpp\
					src/NcursesEvent/NcursesEvent.cpp

ISRC 			=	-I ./include/ArcadeNcurses\
					-I ./include/NcursesEvent\
					-I ../../include/

CXX				=	g++

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

LD_FLAGS 		=	-fPIC -shared -lncurses

OBJ				=	$(SRC:.cpp=.o)

TARGET			=	../../lib/arcade_ncurses.so

.RECIPEPREFIX	=	-

all: $(TARGET)

$(TARGET): $(OBJ)
-$(CXX) $(ISRC) -o $(TARGET) $(OBJ) $(LD_FLAGS)

clean:
-@rm -f $(OBJ)

fclean: clean
-@rm -f $(TARGET)

re: fclean all


%.o:	%.cpp
-$(CXX) $(ISRC) -c -fPIC -o $@ $<

.PHONY:	all clean fclean re
