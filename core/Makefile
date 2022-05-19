##
## EPITECH PROJECT, 2022
## generic makefile
## File description:
## Makefile
##

TARGET			=		../arcade


SRCDIR			=		./src
# ENTRYPOINT		=		$(SRCDIR)/main.cpp
SRC				=		$(shell find $(SRCDIR)/*.cpp)
# ALLSRC			=		$(SRC) $(ENTRYPOINT)


OBJDIR			=		obj
OBJ				=		$(patsubst %.cpp, %.o, $(SRC))
CXX				=		g++
ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif
LDFLAGS			=		-I include -I ../include
CXXFLAGS		=		-Wall -Wextra -g -Werror -std=c++20 -fno-gnu-unique

UTDIR			=		tests/unit_tests
UTSRC			=		$(shell find $(UTDIR)/*.cpp)
UTEST_FILES		=		$(SRC) $(UTSRC)
UTEST_TARGET	=		unit_tests
UTFLAGS			=		$(CXXFLAGS) $(LDFLAGS) --coverage -lcriterion


.RECIPEPREFIX	=	-
.PHONY: clean fclean re objfolder run_tests clean_tests



all: $(TARGET)
- @echo -e "|||||||||||||||| Build Complete |||||||||||||||||||"
- @echo -e "Binary name: $(TARGET)"

$(TARGET): $(OBJ)
- $(CXX) $(LDFLAGS) -o $(TARGET) $(OBJ) -ldl

clean: clean_tests
-rm -f *.o
-rm -rf $(OBJ)

clean_tests:
-rm -f *.gc*
-rm -f $(UTEST_TARGET)


fclean: clean
-rm -f $(TARGET)
-rm -rf $(OBJDIR)
-rm -f $(UTEST_TARGET)

re: fclean all

objfolder: |	$(OBJDIR)

run_tests:	clean_tests $(UTEST_TARGET)

$(UTEST_TARGET):	$(UTEST_FILES)
- @echo "SRC: " $(SRC)
-$(CXX) -o $(UTEST_TARGET) $(UTFLAGS) $(UTEST_FILES)
-./$(UTEST_TARGET)
-gcovr

$(OBJDIR):
-@ echo "recreating obj dir"
- mkdir -p $(OBJDIR)

%.o: %.cpp
-$(CXX) -c $(CXXFLAGS) $(LDFLAGS) -o $@ $<

