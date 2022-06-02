#include "Graphics.h"
//=====================================================================
//���� ������
//---------------------------------------------------------------------------------------
Graphics::Graphics()
{

	m_tex.resize(PICS_AMOUNT);
	m_tex[HELP].loadFromFile("help.png");
	m_tex[PLAY].loadFromFile("play.png");
	m_tex[SOUND].loadFromFile("sound.png");
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
	
	m_font = sf::Font();
	m_font.loadFromFile("C:/Windows/Fonts/Calibri.ttf");
}