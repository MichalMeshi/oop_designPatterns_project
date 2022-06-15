#include "Gift.h"
Gift::Gift(sf::Texture& t, sf::Vector2f f, Level* level) :StaticObj(t, f), m_level(level), m_animation(m_display,GIFT_SPRITE_SHEET_SIZE.x, GIFT_SPRITE_SHEET_SIZE.y)
{
	float x = (rand() % BOARD_GAME_LENGTH-BOARD_GAME_CELL_SIZE) + BEGGINING_OF_BOARD_X;
	float y = (rand() % BOARD_GAME_LENGTH- BOARD_GAME_CELL_SIZE) + BEGGINING_OF_BOARD_Y;
	m_display.update(0, 30);
	m_display.setPosition(sf::Vector2f(x, y));
}