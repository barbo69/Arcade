##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC				=	src/ArcadeSfml/ArcadeSfml.cpp\
					src/ArcadeSfml/LibManagement.cpp\
					src/SfmlComponent/SfmlComponent.cpp\
					src/SfmlComponent/SfmlComponentObject.cpp\
					src/SfmlComponent/SfmlComponentSound.cpp\
					src/SfmlComponent/SfmlComponentText.cpp\
					src/SfmlData/SfmlData.cpp\
					src/SfmlData/SfmlDataFont.cpp\
					src/SfmlData/SfmlDataSound.cpp\
					src/SfmlData/SfmlDataTexture.cpp\
					src/SfmlEvent/SfmlEvent.cpp\
	
ISRC 			=	-I ./include/ArcadeSfml\
					-I ./include/SfmlData\
					-I ./include/SfmlComponent\
					-I ./include/SfmlEvent\
					-I ../../include/

LD_FLAGS 		=	-fPIC -shared -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJ				=	$(SRC:.cpp=.o)

TARGET			=	../../lib/arcade_sfml.so

CXX				=	g++

CXX_FLAGS		=	-g3 --std=c++20 -c -fPIC -fno-gnu-unique

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

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
-$(CXX) $(ISRC) $(CXX_FLAGS) -o $@ $<