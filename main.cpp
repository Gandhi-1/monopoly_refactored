#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "gameboard.h"
#include "property.h"
#include "player.h"
#include <iomanip>
#include <ctime>
using namespace std;
//REFACTORED MAIN
// creating a gameboard object which will be the only object delcared in main


int getPlayerInfo();

int main(void){
    //testing to see if gameboard prints something
    Game_Board adelaide_monopoly;
    int player_count = getPlayerInfo();
    adelaide_monopoly.Display_board();
    adelaide_monopoly.play_game(players,player_count);
}



//added player objects to a vector in the main
int getPlayerInfo()
{
    cout << "How many players will there be? (2-6)" << endl;
    cout << "=====================================" << endl;
    cin >> playercount;
    system("clear"); //->clear output terminal.
    while (playercount > 6 && playercount < 2 && !isdigit(playercount)) //isdigit tests to see if playercount is indeed a integer
    {
        system("clear");
        cout << "Invalid number! Please enter a number from 2 to 6!" << endl
             << endl;
        cout << "Enter player count:" << endl;
        cin >> playercount;
    }
    adelaide_monopoly.make_move = playercount;
    string tempName;

    // creating an array to store players
    //Player *players = new Player[playercount];
    vector <*Player> players;
    for (int i = 1; i <= playercount; i++)
    {
        cout << "Enter Player " << i << " Name: " << endl;
        cin >> tempName;
        // player_object(name,player number);
        //players[i] = Player(tempName, i + 1);
        Player *player[i] = new Player(tempName, i)
        players.push_back(player[i]);
    }
    return player_count;
    //or instead of returning we can create a pointer;
}



//==declaring card objects==
// const int card_count = 6;

// int playercount;


// void getPlayerInfo();
// void mainMenu();
// void make_move();
// void board_Setup();
// void play_game(int userCount, Player *Players);
// int control = 0;

// int main(void)
// {

//     // for(int i =0; i< card_count; i++){
//     //     cards.push_back(card[i]);
//     // }
//     system("clear");

//     // creating a gameboard object

//     // adelaide_monopoly.Game_Board();
//     // create_cards();
//     mainMenu();
// }

// void mainMenu()
// {

//     char input;
//     cout << "Welcome to Adelaide Edition Monopoly" << endl;
//     cout << "it's just like regular monopoly but shoretened!" << endl;
//     cout << "==============================================" << endl;
//     cout << "If you feel you have had enough, press 2 to quit the game. " << endl;
//     cout << "Note the game will only quit if everyone decides to quit" << endl;
//     cout << "Press 1 to start a game!" << endl;
//     cin >> input;

//     system("clear");

//     while (input != '1' && input != '2')
//     {
//         system("clear");

//         cout << "You inputted the wrong number, try again!" << endl
//              << endl;

//         // we should change it to enter to play games and make moves and then have prest control q to quit game (and not display that option explicitly after every move but instead display it at start of game among game rules)
//         cout << "Welcome to Adelaide Edition Monopoly" << endl;
//         cout << "it's just like regular monopoly but shortened!" << endl;
//         cout << "============================" << endl;
//         cout << "  Press 1 to start a game!" << endl;
//         cout << "  Press 2 to quit the game!" << endl;

//         cin >> input;
//     }

//     if (input == '1')

//     {
//         getPlayerInfo();
//     }

//     else
//     {
//         exit(3);
//     }
//     return;
// }

// void getPlayerInfo()
// {
//     cout << "How many players will there be? (2-6)" << endl;
//     cout << "=======================================" << endl;
//     cin >> playercount;
//     system("clear"); //->clear output terminal.
//     while (playercount > 6 && playercount < 2 && !isdigit(playercount))
//     {
//         system("clear");
//         cout << "Invalid number! Please enter a number from 2 to 6!" << endl
//              << endl;
//         cout << "Enter player count:" << endl;
//         cin >> playercount;
//     }
//     adelaide_monopoly.player_count = playercount;
//     string tempName;

//     // creating an array to store players
//     Player *players = new Player[playercount];

//     for (int i = 0; i < playercount; i++)
//     {
//         // Player* Players = new Player[player_count]; this is not what we want to do as we want to call a constructor

//         // It is crucial to note that the first player starts at 1
//         cout << "Enter Player " << i + 1 << " Name: " << endl;
//         cin >> tempName;
//         // player_object(name,player number);
//         players[i] = Player(tempName, i + 1);
//         // this is an alternative way to change the variales individually, but I prefer the above method of calling the constructor
//         //  Players[i].playerName = tempName;
//         //  Players[i].player_num = i + 1;
//         //  Players[i].change_balance(1500);
//     }
//     // we need to dereference players to become a single pointer instead of a double pointer by calling it as *players
//     play_game(playercount, players);
// }

// void play_game(int userCount, Player *Players)
// {

//     int gameConclude;
//     int choice;
//     adelaide_monopoly.Display_Board();
//     while (gameConclude != userCount)
//     {
//         gameConclude = 0;
//         for (int i = 0; i < userCount; i++)
//         {

//             cout << endl
//                  << "Its " << Players[i].get_name() << "'s turn!" << endl;
//             cout << "Press 1 to roll the dice " << endl;
//             cin >> control;

//             if (control == 2)
//             {
//                 gameConclude++;
//             }

//             while (control != 1 && control != 2)
//             {

//                 cout << "Invalid Entry! Try again" << endl;
//                 cout << "Press 1 to roll the dice " << endl;
//                 // cout << "2 - End Game " << endl
//                 cin >> control;
//                 // cout<<"test: control value = "<<control<<endl;
//             }
//             // now making a move for the player
//             Players[i].set_position();

//             // we could make this a funtion
//             adelaide_monopoly.set_user_pos(Players[i]);
//             // printing out the board
//             adelaide_monopoly.Display_Board();

//             if (Players[i].position == 0)
//             {
//                 cout << Players[i].get_name() << " has landed on start!" << endl;
//             }
//             if (Players[i].position == 1)
//             {
//                 AdelaideUni.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 2)
//             {
//                 FlindersUni.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 3)
//             {
//                 UniSA.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 4)
//             {
//                 TAFE.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 5)
//             {
//                 // if the player, was not in jail previously we set their position to jail;
//                 if (Players[i].previous_position != 5)
//                 {
//                     Players[i].in_jail = true;
//                 }
//                 // calling jail functionality
//                 Players[i].InJail();
//             }

//             if (Players[i].position == 6)
//             {
//                 MountLofty.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 7)
//             {
//                 MountOsmond.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 8)
//             {
//                 MorialtaFalls.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 9)
//             {
//                 LinearParkTrail.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 10)
//             {
//                 // cards objects should not be declared here as it is extremely inefficient, however errors arrise whenever I declare them elsewhere. For some reason the card vector is not accessible
//                 // please try and fix this
//                 // we actually don't have to make this dynamic but I chose to do so by choice because I want to move these objects elsewhere in the code
//                 // these card declartions go in the subclass
//                 // call subclass when we land on the function.
//                 // when a player lands on a tile, it calls the ontile subclass
//                 Card *card1 = new Card("You got caught stealing from Burnside Village, go to jail!", 1, 0, 5);
//                 Card *card2 = new Card("Adelaide Uni awards you a game design prize foor OOP, collect a $500 dollar prize", 2, 500, 0);
//                 Card *card3 = new Card("You skipped the line at Centerlink, you loose your 200 dollar allowance for passing start", 2, -200, 0);
//                 Card *card4 = new Card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!", 2, 100, 0);
//                 Card *card5 = new Card("You fell asleep on an O-barn bus, whoops your final bus stop is START!", 1, 0, 0);
//                 Card *card6 = new Card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!", 2, 100, 0);

//                 vector<Card *> cards;
//                 // i can't seem to figure out why cards is an undeclared identifier when it is cleary declared here
//                 cards.push_back(card1);
//                 cards.push_back(card2);
//                 cards.push_back(card3);
//                 cards.push_back(card4);
//                 cards.push_back(card5);
//                 cards.push_back(card6);
//                 // std::srand*(std::time(nullptr)); //set rand seed
//                 int choice = std::rand() % card_count;
//                 // alternative syntax used to flex programming skills XD
//                 //*(cards+choice)->activate_card(Players,adelaide_monopoly,i);
//                 cards[choice]->activate_card(Players, adelaide_monopoly, i);
//                 // Chance.ontile(Players,i,playercount);
//             }

//             if (Players[i].position == 11)
//             {
//                 BurnsideVillage.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 12)
//             {

//                 NorwoodParade.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 13)
//             {
//                 RundelMall.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 14)
//             {
//                 TTP.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 15)
//             {
//                 // GoToJail.ontile(Players[i]);
//                 // calling a jail class an jail object
//             }

//             if (Players[i].position == 16)
//             {
//                 RAH.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 17)
//             {
//                 AdelaideOval.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 18)
//             {
//                 StBernards.ontile(Players, i, playercount);
//             }

//             if (Players[i].position == 19)
//             {
//                 Hindley.ontile(Players, i, playercount);
//             }
//         }
//     }
// }
