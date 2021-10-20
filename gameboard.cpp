
#include "gameboard.h"
//as Property inherets tile we can go property->tile_method() and it should be able to access all the features of the tile
// default constructor
Board::Board()
{
    //creating player objects in board constructor
    // these go in board class
    //if we want to use vector<Property*> properties;
    // Property *property1 = new adelaide_uni("Adelaide Uni", 200, 40, 1);
    // properties.push_back(property1);
    //we need to change this to tile and have property objects pointing to the tile objects
    //Property AdelaideUni(rent,owner,number) = &adelaideUni_tile_object
    //AdelaideUni-> do_something

    Property *p1 = new AdelaideUni("Adelaide Uni", 200, 40, 1);
    Property *p2 = new FlindersUni("Flinders Uni", 150, 20, 2);
    Property  *p3 = new UniSA("UNISA", 155, 22.5, 3);
    Property *p4 = new TAFE("TAFE", 160, 25, 4);
    Property *p5 = new Jail("Jail", 0, 200, 5);
    Property *p6 =  new MountLofty("Mount Lofty", 250, 50, 6);
    Property *p7 = new MountOsmond("Mount Osmond", 225, 45, 7);
    Property *p8 = new MorialtaFalls("Morialta Falls", 230, 46.5, 8);
    Property  *p9 = new LinearParkTrail("Linear Park Trail", 245, 47, 9);
    Property *p10 = new Chance("Chance", 0, 0, 10);
    Property *p11 = new BurnsideVillage("Burnside Village", 225, 45, 11);
    Property *p12 = new NorwoodParade("Norwood Parade", 185, 30, 12);
    Property *p13 = new RundelMall("Rundel Mall", 300, 70, 13);
    Property *p14 = new TTP("Tea Tree Plaza", 280, 60, 14);
    Property *p15 = new goJail("go to jail", 0, 0, 165;
    Property *p16 = new RAH("RAH Hospital", 380, 80, 16);
    Property *p17 = new AdelaideOval("Adelaide Oval", 400, 70, 17);
    Property *p18 = new StBernards("St Bernards", 420, 50, 18);
    Property *p19 = new Hindley7("Hindley club", 420, 50, 18);
    
    properties.push_back(*p1);
    properties.push_back(*p2);
    properties.push_back(*p3);
    properties.push_back(*p4);
    properties.push_back(*p5);
    properties.push_back(*p6);
    properties.push_back(*p7);
    properties.push_back(*p8);
    properties.push_back(*p9);
    properties.push_back(*p10);
    properties.push_back(*p11);
    properties.push_back(*p12);
    properties.push_back(*p13);
    properties.push_back(*p14);
    properties.push_back(*p15);
    properties.push_back(*p16);
    properties.push_back(*p17);
    properties.push_back(*p18);
    properties.push_back(*p19);
    //adding properties to a property array
    // properties.push_back(AdelaideUni);
    // properties.push_back(FlindersUni);
    // properties.push_back(UniSA);
    // properties.push_back(TAFE);
    // properties.push_back(Jail);
    // properties.push_back(MountLofty);
    // properties.push_back(MountOsmond);
    // properties.push_back(MorialtaFalls);
    // properties.push_back(LinearParkTrail);
    // properties.push_back(BurnsideVillage);
    // properties.push_back(NorwoodParade);
    // properties.push_back(RundelMall);
    // properties.push_back(TTP);
    // properties.push_back(RAH);
    // properties.push_back(AdelaideOval);
    // properties.push_back(StBernards);
    // we actually need to pass this property array into other functions for it to be used
    //cout << "default constructor called" << endl;
  
}
// sets user position on gameboard by modifying array
// we could later integrate this function elsewhere with set_position() in player class

//most of the main classes are being moved into the gameboard classes



void Board::make_move(Player* players,int num_players){
    int game_conclude = 0;
    int user_count = num_players;
    while (gameConclude != userCount)
    {
        gameConclude = 0;
        for (int i = 0; i < userCount; i++)
        {
            cout<< "Its " << Players[i].get_name() << "'s turn!" << endl;
            cout << "Press 1 to roll the dice " << endl;
            cin >> control;

            if (control == 2)
            {
                gameConclude++;
            }

            while (control != 1 && control != 2)
            {

                cout << "Invalid Entry! Try again" << endl;
                cout << "Press 1 to roll the dice " << endl;
                // cout << "2 - End Game " << endl
                cin >> control;
            }
            //rolls the dice;
            Players[i].set_position();
            set_user_pos(Players[i]);
            Display_Board();
        }

}

void Board::set_user_pos(Player player)
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

void Board::Display_Board()
{
    // holds our properties.

    // cout << "player p2's move" << endl;
    // the game board should access the values declared in the constructor
    // pull name from property instead;
    //string array[20] = {"START", "Adelaide Uni", "Flinders Uni", "Uni SA", "Tafe", "Jail", "Mount lofty", "Mount osmond", "Morialta falls", "Linear park trail", "Chance", "Burnside Village", "Norwood Parade", "Rundel Mall", "Tea Tree Plaza", "Go to Jail", "RAH hospital", "Adelaide Oval", "St Bernards F&V", "Hindley club"};
    cout << " ===========================================================================================================================================" << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        //we want to format the name of the property/tile and get_the name from the object
        cout << left << setw(20) << properties[i]->get_name(); << "|  ";
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
        cout << " |  " << setw(20) << properties[19-i]->get_name() << "|"
             << setw(92) << ""
             << "| " << setw(20) << properties[i + 6]->get_name() << "|" << endl;
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
        cout << setw(20) << properties[15 - i]->get_name() << "|  ";
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
// int Board::rollDice()
// {
//     int dice_roll = rand() % 12 + 1;
//     return dice_roll;
// }
