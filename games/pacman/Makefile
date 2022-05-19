##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CXX				=	g++

CXXFLAGS		=	-g3 -c -fPIC -shared $(ISRC) -std=c++20

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

SRC				=	src/PacmanGame/PacmanGame.cpp\
					src/PacmanGame/LibManagement.cpp\
					src/PacmanMap/PacmanMap.cpp\
					src/PacmanComponent/PacmanComponent.cpp\
					src/PacmanComponent/ComponentText.cpp\
					src/PacmanComponent/TextGameOver.cpp\
					src/PacmanComponent/TextWin.cpp\
					src/PacmanComponent/TextScore.cpp\
					src/PacmanComponent/TextScoreNb.cpp\
					src/PacmanComponent/TextReset.cpp\
					src/PacmanComponent/ComponentSound.cpp\
					src/PacmanComponent/ComponentObject.cpp\
					src/PacmanComponent/ObjectPacman.cpp\
					src/PacmanComponent/ObjectRedGhost.cpp\
					src/PacmanComponent/ObjectPinkGhost.cpp\
					src/PacmanComponent/ObjectBlueGhost.cpp\
					src/PacmanComponent/ObjectYellowGhost.cpp\
					src/PacmanComponent/ObjectMap.cpp\
					src/PacmanComponent/ObjectBigPacGum.cpp\
					src/PacmanComponent/ObjectLitPacGum.cpp\
					src/PacmanAnim/PacmanAnim.cpp\
					src/PacmanAnim/AnimPacman.cpp\
					src/PacmanAnim/AnimRedGhost.cpp\
					src/PacmanAnim/AnimPinkGhost.cpp\
					src/PacmanAnim/AnimBlueGhost.cpp\
					src/PacmanAnim/AnimYellowGhost.cpp\
					src/PacmanEvent/PacmanEvent.cpp\
					src/PacmanScore/PacmanScore.cpp\
					src/PacmanError/PacmanError.cpp\
					src/PacmanError/MapError.cpp\
					src/PacmanError/ComponentError.cpp
	
ISRC 			=	-I include/PacmanGame\
					-I include/PacmanMap\
					-I include/PacmanComponent\
					-I include/PacmanAnim\
					-I include/PacmanEvent\
					-I include/PacmanScore\
					-I include/PacmanError\
					-I ../../include/

LD_FLAGS 		=	-fPIC -shared

CXX				=	g++

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

CXXFLAGS		=	-g3 --std=c++20 -Werror -c -fPIC

OBJ				=	$(SRC:.cpp=.o)

TARGET			=	../../lib/arcade_pacman.so

.RECIPEPREFIX	=	-

all: $(TARGET)

$(TARGET): $(OBJ)	
-$(CXX) $(ISRC) -o $(TARGET) $(OBJ) $(LD_FLAGS)

clean:
-rm -f $(OBJ)

fclean: clean
-rm -f $(TARGET)

re: fclean all

%.o:	%.cpp
-$(CXX) $(ISRC) $(CXXFLAGS) -o $@ $<
