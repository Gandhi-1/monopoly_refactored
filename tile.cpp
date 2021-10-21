#include <string>
#include "player.h"

Tile::Tile() {

    tileName = "";


}

Tile::Tile(string name) {

    tileName = name;


}

Tile::~Tile() {
    cout << tileName << " has been deleted!" << endl;
}
