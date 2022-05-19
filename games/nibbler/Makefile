##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## Makefile
##

TARGET			:=	../../lib/arcade_nibbler.so

CXX				=	g++
CXXFLAGS		=	-c -fPIC -shared -I include -std=c++20 -fno-gnu-unique

ifneq ("${env}", "")
	CXXFLAGS += -D ENV=${env} -D LOGPATH=${logpath}
endif

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

LD				=	g++
LD_FLAGS		=	-fPIC -shared

SRC				=	src/NibblerComponent.cpp \
					src/NibblerGame.cpp	\
					src/LibManagement.cpp \
					src/Event.cpp \
					src/Snake.cpp	\
					src/Timer.cpp	\
					src/ScoreBoard.cpp

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