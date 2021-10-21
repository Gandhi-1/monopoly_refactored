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

int main(void){
    //initialising array of card objects
    std::vector<Card*> cards;
    cards.push_back(new Card("You got caught stealing from Burnside Village, go to jail!",1,0,5));
    cards.push_back(new Card("Adelaide Uni awards you a game design prize foor OOP, collect a $500 dollar prize",2,500,0));
    cards.push_back(new Card("You skipped the line at Centerlink, you loose your 200 dollar allowance for passing start",2,-200,0));
    cards.push_back(new Card("St benards fruit and vegetables got attacked by ALDI staff for being too cheap, you volenteer 200 dollars out of pocket to help fix the store",2,-200,0));
    cards.push_back(new Card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!",2,100,0));
    cards.push_back(new Card("You fell asleep on an O-barn bus, whoops your final bus stop is START!",1,0,0));

    //initialising lucky player who gets 6 chance cards in a row
    Player *p1 = new Player("p1",1);

    //initialising board for testing
    Board* adelaide_monopoly = new Board();


    //testing each card's effects on the user:
    for(int i = 0; i<6;i++){
        cards[i]->activate_card(p1,(*adelaide_monopoly),0);
        cout << "Card " << i << "\n Description: " << cards[i]->header << "\n Player properties: " << endl;
        cout << "previous position: " << p1->get_previous_position() << ", current position: " << p1->get_position() << ", Balance: " << p1->get_balance() << ", inJail: " << p1->in_jail;
    }


    //end program
    delete p1;
    delete adelaide_monopoly;
    return 0;
}
