
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

//#include "space.h"
//#include "move_action.h"
#include "player.h"
#include "property.h"
#include <iomanip>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;

class Player;
//we need to use forward declaration. This is important due to the order of object calls
class Game_Board
{
public:
//class variables
	//string array[21];
	std::vector<string> *user_pos = new vector<string>(20);
	//std::vector<string> *property = new vector<string>(20);
	//declaring a pointer to an array
	//string * array;
	// string user_pos[20];
	int variable;
	int player_count;
//class methods
	Game_Board();
	void Display_Board();
	void player_position(string player);
	void set_user_pos(Player player);
	int rollDice();

	//create players should be done in the main function, not in our gameboard class.
	// Player* createPlayers(int numPlayers);
	// Player* playerList;
};
#endif