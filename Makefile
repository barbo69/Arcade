##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

.PHONY: clean fclean re core games graphicals


all: core games graphicals


clean:
	make clean -C graphics
	make clean -C games
	make clean -C core

fclean:
	make fclean -C graphics
	make fclean -C games
	make fclean -C core


re: fclean all

core:
	make -C core

games:
	make -C games

graphicals:
	make -C graphics

docs:
	rm -rf documentation/html documentation/latex
	doxygen documentation/doxygen.conf