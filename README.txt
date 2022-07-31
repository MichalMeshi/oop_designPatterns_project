Xonix game
Introduction to Object Oriented Programming Final Project.
Written by:Michal Meshi Zahav. (and Penina Schuss)

Video of the project: https://youtu.be/0J7pFZekrgg

In this project we implemented the Xonix game "Conquering territories", using the SFML library.

The classes in the program and their role:
AddTimeGift 
A gift that adds life. Inheritance from the Gift class
Animation
A class that manages the animations in the project.
BackSoundCommand 
A command for managing the background music in the program. Inherited from Command 
Board 
A department that is responsible for everything related to the game board. 
CanMoveToPlace 
Class responsible for movement permissions of the enemies. (used for Strategy) 
CollisionHandling 
A class that manages the collisions in the game. (uses MultyMethod) 
Command 
Parent class for all menu commands. (Command design pattern) 
Controller 
A class that manages the game. 
Display 
A class that wraps images and is responsible for all operations related to them. 
DynamicObj 
A class from which all moving objects in the game inherit. 
Enemies 
The class  for the enemies in the game. 
EnemyFactory 
Class thats in charge of creating the enemies (Factory pattern) 
FreezeEnemiesGift 
A gift that freezes the enemies on the board. Inherited from Gift. 
GameController 
A class thats in charge of  running the game and managing its stages. 
Gift 
A class from which all gifts are inherited. 
GiftFactory 
A class thats in charge of producing a gift in a raffle. (Factory design) 
Graphics 
The Singleton class, where all the sound textures, etc. are located. 
ImmunePlayer 
A class that inherits from player, this is an immune player created for a limited time following a collision with a gift that gives immunity. 
ImmunityGift 
The gift that makes the player immune for a limited time. (inherited from Gift) 
InfoOfLevel 
A class where the data is stored for each step. 
InformationDisplay 
A class where everything related to the menu that appears on the board during the entire game is found. 
KillEnemyGift 
A gift that makes the player become a killing player, and kill all the enemies he collides with. (inherited from Gift) 
KillingPlayer 
A class that inherits from Player. This is a player thats able to kill  for a limited time, following a collision with the gift above. 
Level 
A class that manages the current stage of the game. 
LifeGift 
Inherited from Gift, a gift that adds life. 
Menu 
All game menus inherit from this class. (Command) 
Move 
From this class, the types of movements classes (Strategy) inherit 
MoveEverywhere 
A class responsible for moving all the board tiles. Inherited from CanMoveToPlace 
MoveToBlocked 
A class responsible for moving only the tiles blocked on the board. Inherited from CanMoveToPlace 
MoveToUnBlocked 
A class responsible for moving only the tiles that are not blocked by the board. Inherited from CanMoveToPlace 
NewGameCommand 
The command to run the game. Inherited from Command 
NoiseCommand 
The command to manage the audio of the background sounds in the game. Inherited from Command 
Object 
A class from which all objects in the game inherit. 
Player 
The player's department. 
RandomMove 
The department responsible for random displacement. Inherited from Move 
SettingsCommand 
The "show settings" command. Inherited from Command 
SettingsMenu 
the settings menu. Inherited from Menu 
ShowInstructionsCommand 
The game instructions display command. Inherited from Command 
SimpleMove 
A class responsible for simple movement on the board. Inherited from Move 
SmartMove 
A class responsible for intelligent movement that follows the player. Inherited from Move 
StartMenu 
The initial menu, inherits from Menu 
StaticObj 
A class from which all static objects in the game inherit. Inherits from Object 
TerritoryEater 
An enemy that inherits from Enemies. He is a special enemy that eats occupied territories and makes them empty.

Main data structures and their roles: 
We used uniqe_ptr vectors for the enemies and gifts. 
We used vector over vector for the board matrix.

Noteworthy algorithms: 
We used several design patterns: 
We used MultyMethod to manage the collisions. 
We used factory+strategy design patterns for building the enemies, which have a pointer for the type of movement. When the move class has an additional pointer for the type of squares the enemy is allowed to move to. (strategy within strategy)
We used the factory design pattern for building raffled gifts during the game. 
We used Command within Command design pattern for the primary menu, within which there is a secondary menu of settings. 
We used singleton design pattern for the Graphics class where all Textures, Sounds, the game window, etc. are located. That way all classes "know" this class and can easily get what they need from it.
In addition, we used the recursive algorithm: FloodFIll for coloring the area occupied by the player.

General Comments: 
It is very easy to upgrade the game and add stages. 
You can easily create another type of enemies - simply add another class of movement and combine with one of the classes of "on which squares it is allowed to walk", and create the new enemy in facrory.
 
Game rules: 
The player's goal is to conquer the requested area at each stage. 
He has a number of lives, when they run out and the player is eliminated the game is over. 
The reasons that lower a player's life: If he meets the enemy (except for those who eat territories). 
If he moves on a place that is in the middle to occupy (a place marked with a circle) 
If time runs out.

The enemies in the game: 
Stupid enemy - travels on the board. On all types of terrain (occupied and not occupied) 
Clever Enemy - Chases the player. Travels all over the board. 
Ball - its role is to travel only in unoccupied territory. If the player surrounds an area that contains the enclosed area the enclosed area is not occupied. 
Eats territories - eats the territories conquered by the player.

Types of gifts: 
extra life 
extra time 
Freezing enemies for a few seconds 
A gift that makes the player immune for a few seconds 
A gift that makes the player kill all the enemies he encounters (except for the unkillable area food) for a few seconds.
