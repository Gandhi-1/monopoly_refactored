#include <string>
#include "player.h"

Tile::Tile() {

    tileName = "";


}

Tile::Tile(string name) {

    tileName = name;


}

string Tile::get_name() {

    return tileName;

}


Tile::~Tile() {
    cout << tileName << " has been deleted!" << endl;
}
