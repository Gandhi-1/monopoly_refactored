#this is our makefile to compile our code so that we don't have to manually compile it all. All header files need to be included as dependencies
#I have only included the files I think are necessary for our game to function in our  make file, feel free to add more after.
# monopoly: test_main.cpp  player.cpp  player.h property.cpp property.h gameboard.cpp gameboard.h
# 	clang++ test_main.cpp player.cpp gameboard.cpp property.cpp -o monopoly

#unit testing
monopoly: test_main.cpp gameboard.cpp gameboard.h player.cpp player.h property.cpp property.h 
	clang++ test_main.cpp gameboard.cpp player.cpp property.cpp -o monopoly


#actual game 
monopoly1: main.cpp gameboard.cpp gameboard.h player.cpp player.h property.cpp property.h card.cpp card.h
	clang++ main.cpp gameboard.cpp player.cpp property.cpp card.cpp -o monopoly1
