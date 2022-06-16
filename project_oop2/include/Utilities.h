#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
//------------------------------

const sf::Vector2f CLOCK_ICON_POSITION = { 1400,45 };
const sf::Vector2f BEGGINING_WINDOW = { 0,0 };
const sf::Vector2f LEVEL_TXT_POSITION = { 20,20 };
const sf::Vector2f NUM_LEVEL_TXT_POSITION = { 120,10 };
const sf::Vector2f TIME_LEFT_TXT_POSITION = { 105,130 };
const sf::Vector2f FIRST_HEART_POSITION = { 10, 5 };
const sf::Vector2f BOARD_GAME_CELL = { 20,20 };
const sf::Vector2f GIFT_SPRITE_SHEET_SIZE = { 270,30 };
const sf::Vector2f PLAYER_SPRITE_SIZE = { 40,40 }; 
const sf::Vector2f CRUMS_SPRITE_SHEET_SIZE = { 500,100 }; 
const sf::Vector2f LEVEL_UP_SIZE = { 500, 150 };
const sf::Vector2f GAME_OVER_SIZE = { 500, 150 };
const sf::Vector2f EXPLOSION_SPRITE_SHEET_SIZE = { 4500,900 };
const sf::Vector2f BEGGINIG_OF_MATRIX = { 350,50 };
const sf::Vector2f MIDDLE_MATRIX = { 800,500 };
const sf::Vector2f WIN_SIZE = { 800,500 };
const sf::Vector2f COMMAND_PIC_SIZE = { 200, 200 };
const sf::Vector2f HELP_POSITION = { 600, 400 };
const sf::Vector2f SOUND_POSITION = { 820, 400 };
const sf::Vector2f NOISE_POSITION = { 1040, 400 };
const sf::Vector2f BACK_BOTTON_SIZE = { 100, 100 };

const sf::Vector2i LEFT = { -1, 0 };
const sf::Vector2i RIGHT = { 1, 0 };
const sf::Vector2i UP = { -1, 0 };
const sf::Vector2i DOWN = { 1, 0 };
const sf::Vector2i BEGGIN_WINDOW = { 0, 0 };




const int AMOUNT_OF_SOUNDS = 6;
const int MIDDLE_BOARD_X = 800;
const int MIDDLE_BOARD_Y = 500;
const int DIRECTIONS_AMOUNT = 4;
const int MATRIX_SIZE = 45;
const int ZERO = 0;
const int ENEMY_PIC_SIZE = 30;
const int GIFT_PIC_SIZE = 30;
const int HALF_ENEMY_PIC_SIZE = 15;
const int BEGGINING_OF_BOARD_X = 350;
const int BEGGINING_OF_BOARD_Y = 50;
const int BOARD_GAME_LENGTH = 900;
const int BOARD_GAME_CELL_SIZE = 20;
const int AMOUNT_FOR_ONE_PERCENT = 18;
const int VOLUME = 100;
const int TO_UP = -1;
const int TO_DOWN = 1;
const int TO_RIGHT = 1;
const int TO_LEFT =-1;
const int WIDTH_WINDOW = 1600;
const int HIGTH_WINDOW = 1000;
const int PICS_AMOUNT = 41;
const int SPRITE_SIZE = 70;
const int LEVEL_NUMBER_INDEX = 5;
const int AMOUNT_OF_GIFTS = 5;
const int THREE = 3;
const int FIVE = 5;
const int FIVE_SECONDS = 5;
const int SIX = 6;
const int SEVEN = 7;
const int TWELVE = 12;
const int LEVELS_AMOUNT = 3;
const int HALF_MINUTE = 30;
const int FOR_ASCII_CONVERSION = 48;
const int BIG_JUMP_PIXELS =10;
const int FIFTY_SECONDS =50;
const int FIRST_LEVEL =1;
const int THREE_SECONDS =3;
const int LEFT_LIMIT =370;
const int RIGHT_LIMIT =1230;
const int TOP_LIMIT =70;
const int BOTTOM_LIMIT =930;
const int HALF_COMMAND_PIC_LENGTH =100;
const int LAST_LEVEL =3;

//-------------------------
enum Texture {
	HELP = 0, SOUND, NOISE,PLAY, PLAYER, KILLING_PLAYER,IMMUNE_PLAYER,UN_SOUND, START_VIEW, EXIT, INSTRUCTIONS, SKY, SETTING_VIEW, SETTING, CLOCKPICTURE,BACK,BALL,SPIDER,SMART_SPIDER, HEART,UN_NOISE, TERRITORY_EATER_PIC, EXPLOSION_ANIMATION, CRUMB_ANIMATION,GUN_ANIMATION,
	LEVEL1_EMPTY_TILE,LEVEL1_BLOCKED_TILE,LEVEL1_MIDDLE_TILE, LEVEL2_EMPTY_TILE, LEVEL2_BLOCKED_TILE, LEVEL2_MIDDLE_TILE, LEVEL3_EMPTY_TILE, LEVEL3_BLOCKED_TILE,
	LEVEL3_MIDDLE_TILE,FREEZE_ENEMIES,ADD_TIME,HEART_ICON, LEVEL_UP, WIN_GAME, GAME_OVER,IMMUNE_ANIMATION

};
//-------------------------
enum Sounds {
	FIRST_MUSIC =0,CLICK_SOUND,CLOCK_SOUND,WIN_SOUND,GIFT_SOUND, FAILURE_SOUND
};
//-------------------------
enum TileState {
	AROUND_ENEMY=-1,EMPTY = 0,BLOCKED,MIDDLE
};
//-------------------------
enum MoveEnum {
	SIMPLE_MOVE = 0, SMART_MOVE, MOVE_FAR, RANDOM_MOVE,E_MOVE_MAX_SIZE
};
//-------------------------
enum  WhereCanMoveEnum {
	MOVE_TO_BLOCKED = 0, MOVE_TO_UNBLOCKED, MOVE_EVERYWHERE, E_WHERE_CAN_MOVE_MAX_SIZE
};
//-------------------------
enum  EndOfLevelCondition {
	CLOSE = 0, FINISHLEVEL, FAIL_LEVEL, JUST_FOR_VISUAL
};
//-------------------------
enum  InfoOfLevelEnum {
	TERRITORY_EATER = 0,DOMB_MONSTER,SMART_MONSTER, PERCENTAGE,LIFE_AMOUNT, INDEX_OF_BLOCKED, INDEX_OF_EMPTY, INDEX_OF_MIDDLE
};
 
