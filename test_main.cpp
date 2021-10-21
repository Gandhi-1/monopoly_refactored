#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "gameboard.h"
#include "property.h"
#include "player.h"
#include <iomanip>
//added this library for random 
#include <ctime>
//#include <ncurses.h>
using namespace std;

//==game board==
Board adelaide_monopoly;

//==player objects==
Player  p1("p1", 1);
Player p2("p2", 2);
 
// Player* players = new Player[2]; 
// players[1] = Player("p1", 1); 

// players[0] = p1; players[1] = p2
// players[0] = Player("p1", 1);
// players[1] = Player("p2", 2);

//creating global properties outside of class so that they can be accessed for teting;
    

int main(void)
{
    std::vector<Property*> properties;
    
    Property* p1 = new Property("Start", 0, 0, 0);
    //these remain properties because they are properties
    Property* p2 = new Property("Adelaide Uni", 200, 40, 1);
    Property* p3 = new Property("Flinders Uni", 150, 20, 2);
    Property* p4 = new Property("UNISA", 155, 22.5, 3);
    Property* p5 = new Property("TAFE", 160, 25, 4);
    //Jail* p16 = new Jail("jail", 0, 0, 165);
    Property* p6 = new Property("Jail", 0, 200, 5);
    Property* p7 = new Property("Mount Lofty", 250, 50, 6);
    Property* p8 = new Property("Mount Osmond", 225, 45, 7);
    Property* p9 = new Property("Morialta Falls", 230, 46.5, 8);
    Property* p10 = new Property("Linear Park Trail", 245, 47, 9);
    Property* p11 = new Property("Chance", 0, 0, 10);
    Property* p12 = new Property("Burnside Village", 225, 45, 11);
    Property* p13 = new Property("Norwood Parade", 185, 30, 12);
    Property* p14 = new Property("Rundel Mall", 300, 70, 13);
    Property* p15 = new Property("Tea Tree Plaza", 280, 60, 14);
    //this should be part of the jail class
    //Jail* p16 = new Jail("go to jail", 0, 0, 165);
    Property* p16 = new Property("go to jail", 0, 0, 165);
    Property* p17 = new Property("RAH Hospital", 380, 80, 16);
    Property* p18 = new Property("Adelaide Oval", 400, 70, 17);
    Property* p19 = new Property("St Bernards", 420, 50, 18);
    Property* p20 = new Property("Hindley club", 420, 50, 18);

    properties.push_back(p1);
    properties.push_back(p2);
    properties.push_back(p3);
    properties.push_back(p4);
    properties.push_back(p5);
    properties.push_back(p6);
    properties.push_back(p7);
    properties.push_back(p8);
    properties.push_back(p9);
    properties.push_back(p10);
    properties.push_back(p11);
    properties.push_back(p12);
    properties.push_back(p13);
    properties.push_back(p14);
    properties.push_back(p15);
    properties.push_back(p16);
    properties.push_back(p17);
    properties.push_back(p18);
    properties.push_back(p19);
    properties.push_back(p20);
    cout<<"testing board"<<endl;
   

    //adelaide_monopoly.set_user_pos(p1);


    adelaide_monopoly.Display_Board();

    //adelaide_monopoly.properties[p1.get_position()]->onProperty(players, 1, 2);


    // //adelaide_monopoly.make_move();
    // cout << "==testing player functionality==" << endl;
    // // ==player.cpp==
    // cout << p1.get_number() << endl;
    // //expected output = 1; actual == 1

    // p1.aquire_property("Adelaide University");
    // //expected output = p1 owns the following properties Adelaide University; //expected = P1 owns adelaide university
    // //p1.aquire_property(.get_name());
    // //adds property to player object: no expected output
    // p1.show_properties();
    // //expected = p1 owns adelaide uni, start ; actual  =  p1 owns adelaide uni, start ;

    // p1.set_position();
    // //rolls dice no expected output you rolled a number: range(1-12), actual: you rolled a number: 8
    // cout << p1.get_position() << endl;
    // //expected: 8, actual = 8
    // cout << p1.get_name() << endl;
    // //expected p1, actual = p1
    // p1.change_balance(200);
    // //no expedcted output as function does not print. should add 200 dollars to the player balance
    // cout << "player funds: ";
    // cout << p1.get_balance() << endl;
    // //expected: p1 owns 1700; p1 owns 1700;

    // cout << "==testing board functionality==" << endl;
    // adelaide_monopoly.set_user_pos(p1);
    // //expected number 2; actual = 2
    // adelaide_monopoly.Display_Board();
    // //prints board
    

    // //==property.cpp==
    // cout << "==testing property functionality==" << endl;
    // // AdelaideUni.buy_property(p1);
    // //Would you like to buy Adelaide University for 200 dollars? yes/no
    // // input = yes
    // //output = CONGRATULATIONS p1 now owns Adelaide University purchased for 200 dollars.

    // //input = no
    // //output = "you chose not to buy this property"

    // //functionality error: player can buy property twice. I will use a bool to stop this from happening
    // //adelaide_monopoly->*properties[2].set_owner(p1);

    // // AdelaideUni.get_owner();
    // // AdelaideUni.ontile(p1);
    // // cout << AdelaideUni.get_name() << endl;

    // // //I might need to use a d
    // // p1.set_position();
    // // adelaide_monopoly.set_user_pos(p1);
    // // //testing to see if player moves subsequently
    // // adelaide_monopoly.Display_Board();
}
