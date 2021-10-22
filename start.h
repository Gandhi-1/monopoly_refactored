#ifndef START_H
#define START_H

#include "tile.h"
#include "player.h"
#include <string>

using namespace std;

class Player;

class Start : public Tile {
public:
    Start();
    Start(string tileName);
    ~Start();
    void onTile(Player* player, int i, int playercount);
    void passStart(Player* player);

};


#endif //STAR_H