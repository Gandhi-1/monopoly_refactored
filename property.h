#ifndef PROPERTY_H
#define PROPERTY_H
#include "player.h"
#include "gameboard.h"
#include "tile.h"
#include <iostream>
#include <string>
using namespace std;
class Player;
//class Game_Board;
//string *properties;

class Property :public Tile {

private:
    bool owned;

protected:
    int num_house, num_hotel;
    int increase;

public:
    int board_position;
    int price;
    //string *properties;
    int rent;
    int ownerNumber;
    string property_owner;
    Property();
    Property(string name, float price, float rent, int board_position);
    void add_value(int increase);
    //for some reason player object is not registering
    void buy_property(Player buyer);
    void set_owner(Player owner);
    void get_owner();
    void getRent(Player player);
    void ontile(Player* player, int i, int playercount);
    void sellProperty(Player* players, int i, int playercount);
    string get_name();
};


#endif