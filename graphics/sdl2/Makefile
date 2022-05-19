##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## Makefile
##

TARGET			=	../../lib/arcade_sdl2.so

CXX				=	g++
CXXFLAGS		=	-c -fPIC -shared -I include -std=c++20 -fno-gnu-unique

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

LD				=	g++
LD_FLAGS		=	-fPIC -shared -lSDL2 -lSDL2_image `sdl-config --libs` -lSDL2_ttf

SRC				=	src/Display.cpp \
					src/Event.cpp	\
					src/LibManagement.cpp

OBJ				=	$(SRC:.cpp=.o)

.RECIPEPREFIX	=	-
.PHONY: all clean fclean re

all:	$(OBJ)
-$(LD) $(LD_FLAGS) -o $(TARGET) $(OBJ)

clean:
-rm -f src/*.o

fclean:	clean
-rm -f $(TARGET)

re: fclean all

%.o:	%.cpp
-$(CXX) $(CXXFLAGS) -o $@ $<
