#include "card.h"

Card::Card(){
    change_balance = 0;
    change_position = 0;
    header = "empty card";

}
//cards do two things (for now), either changes position or changes bank balance; 
 Card::Card(string header, int action_type, int change_balance, int change_position){
     this->change_balance = change_balance;
     this->change_position = change_position;
     this->header = header;
     
 }


//num refers to the player num so we can access the player num in the player object array
 void Card::activate_card(Player *players,Game_Board board, int num){
     //action type determines the functionality of the card, i.e which methods it will call. 
     switch(action_type){
         case 1: 
            changePosition(players, board, num);
            break;
        case 2: 
             changeBalance(players,num);
            break;
        // case 3: 
        //     break
        default:
            break;
     }

 }

//the reason I choose to access the array of all the players instead of simply one player is that we want to access other players in order to give them benifits
//cards can have positive or negative implications
//action_type = 1
 void Card::changePosition(Player * players, Game_Board board, int num){
     cout<<header<<endl;

     //changing user position on board class;
     board.set_user_pos(players[num]);
     players[num].position = change_position;
    //the rest will be done in the main
    //  if(position == 5){
    //      player.in_jail = true;
    //  }
}

//action_type = 2;
void Card::changeBalance(Player * players, int num){
    cout<<header<<endl;
    players[num].change_balance(change_balance,'+');
}

Card::~Card(){
    cout<<"you card was placed back in the deck!"<<endl;
}
    //we want to delete other objects used in this class if they are copied over;
    //deleting card object once used;   