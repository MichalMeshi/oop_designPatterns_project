#pragma once
//------------------------------
const int WIDTH_WINDOW = 1600;
const int HIGTH_WINDOW = 1000;
const int PICS_AMOUNT = 9;
const int SPRITE_SIZE = 70;
const int LEVEL_NUMBER_INDEX = 5;
//-------------------------
enum Texture {
	HELP = 0, PLAY, SOUND, START_VIEW, EXIT, INSTRUCTIONS, SEA, SETTING_VIEW, SETTING
};
//-------------------------
enum TileState {
	EMPTY = 0,BLOCKED,MIDDLE
};