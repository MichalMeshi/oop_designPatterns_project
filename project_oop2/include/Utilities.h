#pragma once
#include <SFML/Graphics.hpp>
//------------------------------
const int WIDTH_WINDOW = 1600;
const int HIGTH_WINDOW = 1000;
const int PICS_AMOUNT = 13;
const int SPRITE_SIZE = 70;
const int LEVEL_NUMBER_INDEX = 5;
const int AMOUNT_OF_GIFTS = 3;
const int LEVELS_AMOUNT = 3;
const sf::Vector2f CLOCK_ICON_POSITION = { 20,120 };
const sf::Vector2f LEVEL_TXT_POSITION = { 20,20 };
const sf::Vector2f NUM_LEVEL_TXT_POSITION = { 120,10 };
const sf::Vector2f TIME_LEFT_TXT_POSITION = { 105,130 };

//-------------------------
enum Texture {
	HELP = 0, PLAY, SOUND, START_VIEW, EXIT, INSTRUCTIONS, SEA, SETTING_VIEW, SETTING, CLOCKPICTURE,BACK,BALL,SPIDER
};
//-------------------------
enum TileState {
	EMPTY = 0,BLOCKED,MIDDLE
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
	CLOSE = 0, FINISHLEVEL, FAIL_LEVEL
};
//-------------------------
enum  InfoOfLevelEnum {
	TERRITORY_EATER = 0,DOMB_MONSTER,SMART_MONSTER, PERCENTAGE,LIFE_AMOUNT
};
//-------------------------
enum  DirectionEnum {
	UP = 0, DOWN, RIGHT,LEFT
};
