#ifndef TILE_H
#define TILE_H
#include "player.h"
#include <string>
using namespace std;
class Player;

class Tile {
public:
    Tile();
    Tile(string name);
    ~Tile();
    string tileName;
    virtual void ontile(Player* player, int i, int playercount) = 0;
};


#endif //TILE_H
