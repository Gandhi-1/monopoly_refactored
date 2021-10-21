Change_log

==20/9/21== (Dhyan Darji)
-created a gameboard.cpp and headerfile alongside the main function.

==21/9/21== (Dhyan Darji)
-updated a gameboard.cpp, main function, gameboard.h

==24/9/21== (Dhyan Darji)
-created a main, header files and class function foundations developed.
Most notably: main.cpp, player.cpp, tile.cpp (now redundant); house.cpp, hotel.cpp, gameboard.cpp, property.cpp

==24/9/21== (Dhyan Darji)
-created a main, header files and class function foundations developed.
Most notably: main.cpp, player.cpp, tile.cpp (now redundant); house.cpp, hotel.cpp, gameboard.cpp, property.cpp

==28/9/21== (Dhyan Darji)
-created property and player class and header file. Updated gameboard class file and header file alongside main function.

==29/9/21== (Dhyan Darji)
-created chance class/header file.
-created gotojail class/header file.
-created hotel class/header file.
-created house class/header file.
-created jail class/header file.
-created tile class/header file -> replaced property with a more generic tile class to allow for inheritance and virtual functions.
-updated property, player, gameboard class/header file alongside main function.

==30/9/21== (Hugh Signoriello)
-updated player class features to include set position, change_balance,get_name  
-debugging and clearing existing code
-Changed variable names for improved clarity

==1/10/21== (Dhyan Darji)
-updated tile, property, player, jail, house, hotel, gotojail, gameboard class/header file.

==1/10/21== (Hugh Signoriello)
-edit_main successfully runs player object class and gameboard class.
-Game successfully runs. Now we need to slowly integarte the other classes into our main. Before we do anything we must ensure thay yhe classes are working.

==3/10/21== (Hugh Signoriello)
-Updated Property class completely; the following are our methods
Property(string name, float price, float rent);
void buy_property(Player buyer);
void set_owner(Player owner);
void ontile(Player player_on_tile);
methods one and two will perhaps be integrated into the one method to avoid errors later on.

==9/10/21== (Dhyan Darji)
-Working on getting all the classes to work together and compile
-Moving into unit testing phase before any more functionality is added!
-get_properties() needs to be modified, we have encountered circular dependency.
-Everything in the main folder now compiles! The only warning is from an unused variable.
-Main started -> now allows user to enter user name and stores this dynamically using a pointer.

==10/10/21== (Dhyan Darji)
-Working on main file
-Loops through players and rolls a dice
-Need to fix up certain functions and make buying/selling easier
-Need to combine with board
-Has a functionality for quitting game
-Need to work on clearing screen at right time.

==11/10/21== (Hugh Signoriello)
-added previous position feature to player class
-improved position changing flow on player calss
-fixed creating objects in mainfile as objects were not called from constructor.

==17/10/21 == (Dhyan Darji)
-Changed ontile functionality into ontile2. Checks if it has been property has been bought and than refers to other functions accordingly.
-Changed vector of pointers of string into a vector of string
-Added player count on gameboard class so it can be accessed easily everywhere.
-Changed up how an array of player objects is created.
-Added a char to change balance so that an integer variable can be passed and money can be added or removed accordingly.
-Made some functions within classes more general so they can fit more than one purpose easily! (Allows us to call sell function with ease if we send a reference to our player pointer instead of just the player on tile)
-Added a selling function that works through auctioning a property. If the property owner is never satisified or is unable to find a buyer, the government will buy it from original price (unfair I know :()
-Removes property from vector after sold and accordingly adds it to the vector of the player who bought it. Money is taken from the player who bought it and is added to the player who sold it nicely!

==17/10/21 == (Hugh Signoriello)
-fixing compilation errors
-fixed choice to buy or sell property or buy house
-added a getter function for player class to return the current properties_owned array. This allows us to view the properties owned by the players in other classes.
-completely updated ontile class and fixed coupling issues
-cleared up code readability and reduced clutter
-added features to main to call our classes in a specific order so that the game runs properly
-changes the dice range to (1,8) instead of (1,12) for balancing
-fixed dynamic array player allocation so that after a player makes a move it no longer shows their previous position on the board
-added feature so that if more than one player lands on a tile, it shows that both players are on that posisition. This can be found in the board.cpp class
-type_casting int to string to add who owns property to board so that it is dipslayed.
-tried to make properties array a pointer so we can access this array from another class without passing it through a function. I wonder how I can do this?

18/10/21 hugh signoriello
-created card class
-created dynamic vector object to hold cards.
-tried other methods including a regular dynamic array but errors occured
-need to figure out how we can instantiate these card objects outside of the card if statement on line 289
-main line 289 needs improving for efficiency
-created card destructor to conserve memory management;

-19/10/21 hugh signoriello
-created in jail method which is part of the player class. If a player's bool in jail == true, this means that they are unable to make moves and will continue to stay in jail unless they meet the special conditions for leaving jail;w
-in jail variables called in main file
-tested jail class and fixed bug from while loop not ending (changed contion to && instead of ||)

Gamebug: not entering a valid player count causes infinite loop

Tutor notes:
-need help to mak
whole class in gameboard.cpp
-want to pass it through and access it from a different file
-don't understand why the card objects have errors when declared outside of the card if statement on line 289 main;
-not sure where I can add inheretance to the game (thinking to create house objects stored inside property object). but objects inside of objects seems inefficient.

-get name from player class

function_get_name( player.get_name + " " + (player.get_number()) //concatenation naturally turns it into a string;
//use tiles

Refactored version:
Gameboard class:
-moved property objects to gameboard constructor;
-added make move method
-fixed up board array to print out the name from the player class

Player class

## ==21/10/2021== (Dhyan Darji)

-Changed makefile to run our program as well (save time)
-We forgot to add a start property, so added that.
-Declared properties correctly and pushed onto the vector of pointers.
-Got rid of redundant variables that are already captured as attributes in classes.
-Input validation has taken place, most work, some might require minor changes!
-Got rid of all if statements for each tile and instead had the predefined function in the board class handle it.
-Made sure the program was memory efficient through passing pointers to vectors/array instead of copying them over.
-Added decontructor for classes that did not have them.
-Added functionality for buying/selling houses/hotels
-Minor bug fixing/logic errors
