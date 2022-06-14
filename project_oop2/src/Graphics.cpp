#include "Graphics.h"
//=====================================================================
//בנאי המחלקה
//---------------------------------------------------------------------------------------
Graphics::Graphics()
{

	m_tex.resize(PICS_AMOUNT);
	m_soundBufferVec.resize(AMOUNT_OF_SOUNDS);
	m_soundVec.resize(AMOUNT_OF_SOUNDS);
	m_tex[HELP].loadFromFile("help.png");
	m_tex[PLAY].loadFromFile("play.png");
	m_tex[PLAYER].loadFromFile("player.png");
	m_tex[SOUND].loadFromFile("sound.png");
	m_tex[UN_SOUND].loadFromFile("unSound.png");
	m_tex[NOISE].loadFromFile("noise.png");
	m_tex[UN_NOISE].loadFromFile("unNoise.png");
	m_tex[START_VIEW].loadFromFile("startView.png");
	m_tex[EXIT].loadFromFile("exit.png");
	m_tex[INSTRUCTIONS].loadFromFile("instructions.png");
	m_tex[SEA].loadFromFile("sea.png");
	m_tex[SETTING_VIEW].loadFromFile("settingsView.jpg");
	m_tex[SETTING].loadFromFile("settings.png");
	m_tex[CLOCKPICTURE].loadFromFile("clock.png");
	m_tex[BACK].loadFromFile("back.png");
	m_tex[BALL].loadFromFile("ball.png");
	m_tex[SPIDER].loadFromFile("spider.png");
	m_tex[HEART].loadFromFile("heart.png");
	m_tex[LEVEL1_BLOCKED_TILE].loadFromFile("level1_blocked_tile.png");
	m_tex[LEVEL1_EMPTY_TILE].loadFromFile("level1_empty_tile.png");
	m_tex[LEVEL1_MIDDLE_TILE].loadFromFile("level1_middle_tile.png");
	m_tex[LEVEL2_BLOCKED_TILE].loadFromFile("level2_blocked_tile.png");
	m_tex[LEVEL2_EMPTY_TILE].loadFromFile("level2_empty_tile.png");
	m_tex[LEVEL2_MIDDLE_TILE].loadFromFile("level2_middle_tile.png");
	m_tex[LEVEL3_BLOCKED_TILE].loadFromFile("level3_blocked_tile.png");
	m_tex[LEVEL3_EMPTY_TILE].loadFromFile("level3_empty_tile.png");
	m_tex[LEVEL3_MIDDLE_TILE].loadFromFile("level3_middle_tile.png");
	m_tex[TERRITORY_EATER_PIC].loadFromFile("territoryEater.png");
	m_tex[EXPLOSION_ANIMATION].loadFromFile("explosionAnimation.png");
	m_tex[CRUMB_ANIMATION].loadFromFile("crumbAnimation.png");

	m_soundBufferVec[FIRST_MUSIC].loadFromFile("music.ogg");
	m_soundBufferVec[WIN_SOUND].loadFromFile("winSound.ogg");
	m_soundBufferVec[CLICK_SOUND].loadFromFile("click.ogg");
	m_soundBufferVec[GIFT_SOUND].loadFromFile("gift.ogg");
	m_soundBufferVec[CLOCK_SOUND].loadFromFile("clock.ogg");
	
	m_font = sf::Font();
	m_font.loadFromFile("C:/Windows/Fonts/Calibri.ttf");
}