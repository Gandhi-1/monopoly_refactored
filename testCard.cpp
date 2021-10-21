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

    //test1:




    //end program
    return 0;
}