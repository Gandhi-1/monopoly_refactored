#include <iostream>
#include <string>
#include "player.h"
#include <random>
//this is a cpp 11 feature
using namespace std;

Player::Player()
{
    position = 0;
    properties_owned[20];
}

Player::~Player() {

}

Player::Player(string Name, int num)
{

    //a player can own a maximum of 20 properties.
    //properties_owned;
    playerName = Name;
    playerBalance = 1500;
    position = 0;
    previous_position = 0;
    player_num = num;
    in_jail = false;
}

void Player::InJail() {
    string input;
    if (in_jail == true) {
        cout << "you are in jail, either pay a 400 dollar bail or roll a two of the same numbers" << endl;
        cout << "would you like to pay the bail? yes/no" << endl;
        cin >> input;
        while (input != "yes" && input != "no") {
            cout << "please type yes or no only" << endl;
            cin >> input;
        }
        if (input == "yes") {
            if (get_balance() >= 400) {
                change_balance(-400);
                cout << "congratulations you are out of jail via the bail" << endl;
                cout << "your account now has " << get_balance() << " dollars" << endl;
                in_jail = false;
                return;
            }
            else {
                cout << "unfortunately you can't afford the bail" << endl;
            }

        }

        int roll_1 = rand() % 6 + 1;
        int roll_2 = rand() % 6 + 1;
        cout << "you rolled a " << roll_1 << " and a " << roll_2 << endl;
        if (roll_1 == roll_2) {
            cout << "congratulations you are out of jail and will be free from your next turn!" << endl;
            in_jail = false;
            return;
        }
        else
        {
            cout << "Unlucky, you aren't free yet!" << endl;
        }
    }

}
int Player::get_number()
{
    return player_num;
}

void Player::aquire_property(string name)
{
    //need to access property in players object and select that specific object into the objet array
    properties_owned.push_back(name);
    //since it is a pointer we need to access it with arrow notation
}
void Player::show_properties()
{
    cout << playerName << " owns the following properties: " << endl;
    for (int i = 0; i < (properties_owned.size()); i++)
    {
        cout << properties_owned[i] << endl;
    }
}

int Player::get_previous_position()
{
    return previous_position;
}
//we should pass through the tiles array in this function to access other classes
void Player::set_position()
{
    previous_position = position;
    //checks if player is in jail and skips the opportunity to make a move and be a free bird!
    if (in_jail == true) {
        cout << "Tough luck buddy, you are in jail! Either pay the 400 dollar bail or take a 1/6 chance to escape via a dice roll" << endl;
        return;
    }
    //has dice roll built into this functoin so that we don't have to constantly call other classes.
    //original method for random number (had issues giving same numbers upon first roll)
    //int roll = rand() % 7 + 1;
    std::random_device dev;
    std:: mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,8);
    int roll = dist6(rng);

    //gets a number between 1 to 8. I have shortened the dice as our game board is shortened. 12 is too powerful for collecting money at go
    cout << "you rolled a " << roll << endl;
    position += roll;
    //it is in our best interest to minimise the amount of object calls.
    if (position >= 19)
    {
        //if the player has passed board, we reset the position.
        position -= 19;
        cout << "congratualtions for passing Go " << playerName << "Centerlink awards you 200 AUD! " << endl;
        //we actually don't need a start class due to this feature.
        //start literally does nothing so it's find to just use this if statment here to simulate the start
        change_balance(200);
    }

    //we also want to call the relevant objects to ther classes 
    // if(position == 5){
    //     tiles[5]->in_jail();
    // }

      // if(position == 10){
    //     chance[10]->active_card();
    // }
    
      // if(position == 15){
    //     tiles[15]->go_to_jail();
    // }
    
}

//this line of code is redundant because we can access variables like such: player_object.position = position variable for that object
int Player::get_position()
{
    return position;
}

string Player::get_name()
{
    return playerName;
}

// function to change balance
void Player::change_balance(int balance)
//, char calculation)
{
    //no need to add symbol as parameter can take either positive or negative balance e.g: change_balance(int -100) would withdraw 100 from user balance
    playerBalance += balance;


}

// function to return balance
int Player::get_balance()
{
    return playerBalance;
}