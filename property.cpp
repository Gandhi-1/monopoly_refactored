#include "player.h"
#include <string>
#include <algorithm>

using namespace std;
// Property default constructor


//the inheretance is done int he main header
Property::Property() :Tile()
{
    owned = false;
    num_house = 0;
    num_hotel = 0;
    price = 0;
    rent = 0;
    board_position = 0;
}



// Property Constructor with name, price and rent
Property::Property(string name, float price, float rent, int board_position) :Tile(name)
{
    owned = false;
    num_house = 0;
    num_hotel = 0;
    //this pointer avoids issue of having name = name
    this->name = name;
    this->rent = rent;
    this->price = price;
    original_name = name;
    property_owner = "none";
    this->board_position = board_position;
}

//we want to change the value of the property as more houses are added. This is because houses pertain value. 
void Property::add_value(int increase) {
    rent += increase;
    //this should be in the hotel class
}

void Property::buy_property(Player buyer)
{
    string input;
    cout << "Would you like to buy " << tileName << " for " << price << " dollars? yes/no" << endl;
    cin.clear(); //clears input

    cin.ignore(256, '\n');

    getline(cin, input);
    // if(input == "yes"){
    if (input.compare("yes") == 0 && buyer.playerBalance > price)
    {
        //if player chooses yes to buy property:
        //setting the player to be the owner of the property
        set_owner(buyer);
        //puts the property to the players bank account

        buyer.aquire_property(tileName);
        //
        owned = true;
        property_owner = buyer.get_name();
        //this line of code adds the buyers number next to the name on the board so that we can see owns the property
        name += " " + buyer.get_number();

        return;
    }
    if (input == "no")
    {
        cout << "You chose not to buy this property" << endl;
    }
    else
    {
        cout << "please type yes or no only" << endl;
        buy_property(buyer);
    }
}

// Function to set owner. //this should be integrated with function on line 25 to be all in one to avoid errors.
void Property::set_owner(Player owner)
{
    //concatenating the player number to the board so that we can see who owns that property
    //we need to typecast int to string before we add it to the
    //==WARNING cause of segmentation fault is this line, fix! or don't use dynamic array
    //properties[board_position]+= " "+std::to_string(owner.get_number());
    cout << "board position is " << board_position << endl;
    //I am struggling to figure out how to make the dynamic array global in all files so I can access the properties array here so I can append the player number
    //cout<<properties<<endl;
    //cout<<properties[board_position]<<endl;
    //properties[board_position]+= to_string(owner.get_number());

    property_owner = owner.get_name();
    //prints out saves player  number who owns the property.
    ownerNumber = owner.get_number();
    cout << "CONGRATULATIONS " << property_owner << " now owns " << tileName << " purchased for " << price << " dollars. " << endl
        << endl;
    //cout << "CONGRATULATIONS " << property_owner << " now owns " << property_name << " purchased for " << price << " dollars. " << endl;
    owned = true;
    return;
}

//gets if a player is ontile
void Property::getRent(Player player)
{
    int owner_number = player.get_number();

    //checking if the property i owned and the owner of the property is a different player (i.e player number is different)

    if (owned && ownerNumber != player.get_number())
    {

        int price_payed = -rent; //our current system enables the player to get into debt.
        cout << player.get_name() << "pays " << -rent << " dollars in rent " << endl;
        player.change_balance(-rent);
        cout << " your account now has " << player.get_balance() << " dollars " << endl;
        get_owner();
    }

    // void Property::ontile(Player player) {
    //     int owner_number = player.get_number();
    //     //checking if the property i owned and the owner of the property is a different player (i.e player number is different)
    //     if (owned && property_owner != player.get_name()) {
    //         int price_payed = -rent; //our current system enables the player to get into debt.
    //         cout << player.get_name() << "pays " << -rent << " dollars in rent " << endl;
    //         player.change_balance(rent);
    //         cout << " your account now has " << player.get_balance() << " dollars " << endl;

    //     }
    // }
}

void Property::get_owner()
{
    cout << "this property is owned by " << property_owner << endl;
}
//this function could be useful to add later to get the name of the property instantiated.
string Property::get_name()
{
    return tileName;
}


//on tile is one of our most important methods. It decides what to do with the player objects once a player lands on a tile.
//i refers to the the player num and is the index of the array
//gets is a player is also on tile; 
//player count gets the number of players
void Property::ontile(Player* players, int i, int playercount) {
    //the i = is just a test to see if the numbers are the same. Since they are, it is obselte to pass through in i in the function.
    //cout<<players[i].get_name()<<" who is "<<i+1<<" = " << players[i].get_number()<<" has landed on "<<property_name<<endl;
    cout << players[i].get_name() << " who is p" << players[i].get_number() << " has landed on " << tileName << endl;
    if (owned == false) {
        //buying a property 
        //this functions handles everything as it is coupled with other functions
        buy_property(players[i]);
        return;
    }
    //if the player lands on someone elses property
    if (owned == true && ownerNumber != players[i].get_number()) {
        //displaying owner
        get_owner();
        getRent(players[i]);
        return;
    }
    //if the player lands on their own property!
    if (owned == true && ownerNumber == players[i].get_number()) {
        //displaying owner
        //calling house class here and creating a house object which increases rent;
        cout << "you already own this property!" << endl;
        cout << "type 'SELL' to sell property otherwise press enter to continue" << endl;
        string sell;
        cin >> sell;
        if (sell == "SELL") {
            sellProperty(players, i, playercount);
        }
        return;
    }



}

//player_num
void Property::sellProperty(Player* players, int i, int playercount)
{

    int maxPrice;

    bool bought = false;
    string input = "";

    //creating a boolean array to store the interested buyers
    bool* interestedBuyer = new bool[playercount];

    for (int j = 0; j < playercount; j++) {
        interestedBuyer[j] = true;
    }

    int count = 0;

    //stores the value of the auction offer in monoply money. The highest bidder will win
    int offer;

    int accept;
    //creating an auction system, bought determines if the property is bought
    while (bought == false) {

        for (int j = 0; j < playercount; j++) {

            if (players[j].get_number() != ownerNumber && interestedBuyer[j] == true) {

                cout << players[j].get_name() << "(" << players[j].get_number() << ") Enter a offer for " << tileName << "if you wish to not purchase enter 0 " << endl;

                while (!(cin >> offer)) {
                    cin.clear(); //clears input

                    cin.ignore(256, '\n');

                    cout << "Input a valid number!" << endl;
                }

                if (offer < players[j].playerBalance) {
                    cout << players[j].get_name() << "(" << players[j].get_number() << ") you have entered an offer that is more than the money you have, you cannot buy this!" << endl;
                    interestedBuyer[j] = false;
                }

                while (offer <= 0) {
                    cout << "Enter a valid offer!" << endl;
                    cout << players[j].get_name() << "(" << players[j].get_number() << ") Enter a offer for " << tileName << "if you wish to not purchase enter 0 " << endl;
                }

                if (offer == 0) {
                    interestedBuyer[j] = false;
                }

                cout << property_owner << "(" << ownerNumber << ")" << " you have received an offer for " << offer << " type 'yes' type 'no' to cancel" << endl;

                cin.clear(); //clears input

                cin.ignore(256, '\n');


                getline(cin, input);

                while (input != "yes" || input != "no")
                    cout << "Type yes or no only please" << endl;
                cin >> input;
            }

            if (input == "yes")
                accept = 1;
            else if (input == "no")
                accept = 0;


            while (accept != 0 || accept != 1) {
                cout << "Invalid answer!" << endl;
                cout << property_owner << "(" << ownerNumber << ")" << " you have received an offer for " << offer << " type 'yes' type 'no' to cancel" << endl;
                cin >> input;
                if (input == "yes")
                    accept = 1;
                else if (input == "no")
                    accept = 0;
            }

            if (accept == 1) {
                cout << "Congrats " << players[j].get_name() << " you have bought the property for " << offer << endl;
                set_owner(players[j]);
                players[j].change_balance(-offer);
                players[i].change_balance(offer);
                name = original_name;
                ownerNumber = players[j].get_number();
                players[i].properties_owned.erase(remove(players[i].properties_owned.begin(), players[i].properties_owned.end(), tileName), players[i].properties_owned.end());
                players[j].properties_owned.push_back(tileName);
                bought = true;

            }
        }
        count++;

        if (count == 3) {
            break;
        }


    }

    if (count == 3) {

        cout << "Nobody wishes to buy the property or you are receiving bad prices, the government will now buy at price bought" << endl;
        players[i].properties_owned.erase(remove(players[i].properties_owned.begin(), players[i].properties_owned.end(), tileName), players[i].properties_owned.end());
        ownerNumber = 0;
        owned = false;
        name = original_name;
        players[i].change_balance(price);

    }

}




