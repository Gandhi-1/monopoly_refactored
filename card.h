
#ifndef Card_h
#define Card_h
#include "gameboard.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;


class Player; 
//we could inheret the player class to access the featurs, but instead I am not going to use inheretance and instead I will use:
//passing by object reference
class Board;

class Card
{

    private:
        string header;
        int action_type;
        int change_balance;
        int change_position;

    public:
        Card();
        Card(string header, int action_type, int change_balance, int change_position);
        void activate_card(Player *players, Board board, int num);
        void changePosition(Player * players, Board board, int num);
        void changeBalance(Player * players, int num);
        ~Card();
        
        
};

#endif