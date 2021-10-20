#ifndef PLAYER_H
#define PLAYER_H
//#include "property.h"
#include "gameboard.h"
#include <string>
#include <vector>
#include <ctime>
//#include "gameboard.h"
using namespace std;

//Player  
class Player {
    // private:
    //     int roll_1;
    //     int roll_2;
    //we want to fix this if it is unecessary
    protected:
        int player_num;
    
    public:
        //variables
        
        vector <string> properties_owned;
        string playerName;
        
        int position;
        int playerBalance;
        int previous_position;
        bool in_jail;
        
        //class methods
        Player(string Name, int num);
        Player();
        void InJail();
        int get_number();
        //this is a very important function that needs to be called when a player lands on the property
        void get_properties(Vector<Tile*> &properties){
            //we want to pass through Tile objects (or property objedcts and access them)

        };
        void aquire_property(string name);
        void show_properties();
        int get_previous_position();
        //makes a move for the player
        void set_position();
        int get_position();
        string get_name();
        //void change_balance();
        int get_balance();
        void change_balance(int balance, char calculation);
};

#endif //PLAYER_H