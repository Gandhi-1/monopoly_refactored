
#include "gameboard.h"

// default constructor
Game_Board::Game_Board()
{
    // user_pos[5] = "p1";
    cout << "default constructor called" << endl;
    // string array[20] = {"START", "Adelaide Uni", "Flinders Uni", "Uni SA", "Tafe", "Jail", "Mount lofty", "Mount osmond", "Morialta falls", "Linear park trail", "Chance", "Burnside Village", "Norwood Parade", "Rundel Mall", "Tea Tree Plaza", "Go to Jail", "RAH hospital", "Adelaide Oval", "St Bernards F&V", "Hindley club"};
    //  for(int i = 0; i<20; i++){
    //      properties->push_back(array[i]);
    //      cout<<array[i]<<endl;
    //      cout<<(*properties)[i]<<endl;
    //  }
    //*array = new string[20];
    //  array = &static_array;
    //  for(int i = 0; i<20; i++){
    //      //array points to the the memory address of this static array and modifies it;
    //      *(array+i) = static_array[i];
    //  }
}
// sets user position on gameboard by modifying array
// we could later integrate this function elsewhere with set_position() in player class
void Game_Board::set_user_pos(Player player)
{
    // changing old position
    int prev_pos = player.get_previous_position();
    (*user_pos)[prev_pos] = "";
    // now updating new position
    int pos = player.get_position();

    // updating old position by setting (*properties) index to be empty
    switch (player.get_number())
    {
    case 1:
        // we want to concatenate player position to either empty or prexisting index incase multiple players are on the same square.
        // the fix for this error is complex: https://stackoverflow.com/questions/56962047/c-error-no-operator-matches-these-operand'
        (*user_pos)[pos] += " p1";
        break;
    case 2:
        (*user_pos)[pos] += " p2";
        break;
    case 3:
        (*user_pos)[pos] += " p3";
        break;
    case 4:
        (*user_pos)[pos] += " p4";
        break;
    case 5:
        (*user_pos)[pos] += " p5";
        break;
    case 6:
        (*user_pos)[pos] += " p6";
        break;
    }
}

void Game_Board::Display_Board()
{
    // holds our properties.

    // cout << "player p2's move" << endl;
    // the game board should access the values declared in the constructor
    // pull name from property instead;
    string array[20] = {"START", "Adelaide Uni", "Flinders Uni", "Uni SA", "Tafe", "Jail", "Mount lofty", "Mount osmond", "Morialta falls", "Linear park trail", "Chance", "Burnside Village", "Norwood Parade", "Rundel Mall", "Tea Tree Plaza", "Go to Jail", "RAH hospital", "Adelaide Oval", "St Bernards F&V", "Hindley club"};
    cout << " ===========================================================================================================================================" << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << left << setw(20) << array[i] << "|  ";
    }
    cout << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << left << setw(20) << (*user_pos)[i] << "|  ";
    }
    cout << endl;
    cout << " ===========================================================================================================================================" << endl;

    for (int i = 0; i < 4; i++)
    {
        // we add numbers for formatting. They seem random but they actually correspond to the amount of spaces needed for the properties to line up.
        cout << " |  " << setw(20) << array[19 - i] << "|"
             << setw(92) << ""
             << "| " << setw(20) << array[i + 6] << "|" << endl;
        cout << " |  " << setw(20) << (*user_pos)[19 - i] << "|"
             << setw(92) << ""
             << "| " << setw(20) << (*user_pos)[i + 6] << "|  " << endl;
        if (i == 3)
        {
            cout << " ===========================================================================================================================================" << endl;
        }
        else
            cout << " ========================                                                                                            =======================" << endl;
    }
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << setw(20) << array[15 - i] << "|  ";
    }
    cout << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << setw(20) << (*user_pos)[15 - i] << "|  ";
    }
    cout << endl;
    cout << " ===========================================================================================================================================" << endl;
    // string p1_properties[4] = {"Rundle Mall", "Hindley st strip club", "Preist P. Benidict's child care", "modbury centerlink"};
    // cout << "Properties owned by player 1: ";
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << setw(20) << p1_properties[i];
    // }
}
// roll dice should be a function in the main. Perhaps it could be in the gameboard class
int Game_Board::rollDice()
{
    int dice_roll = rand() % 12 + 1;
    return dice_roll;
}
