#include "Enemies.h"
#include "Level.h"
//------------------------------------------------------------
Enemies::Enemies(sf::Texture& t, std::shared_ptr<Move> m, Level* l)
	:DynamicObj(t, sf::Vector2f(30, 30)), m_move(m), m_prevMove(m_move), m_level(l)
{
	m_display.setOrigin(ENEMY_PIC_SIZE/2,ENEMY_PIC_SIZE/2);
}
//פונקציה האחראית על תזוזת האויב
//------------------------------------------------------------
void Enemies::move(Board& b)
{ 
	if (m_move != nullptr)
	{
		m_display.setPosition(m_move->move(b));
		m_display.rotate();
	}
}
//פונקציה האחראית על הורדת החיים 
//------------------------------------------------------------
void Enemies::reduceLife() 
{
	m_level->handleFailure();
}
// פונקציה האחראית על הפעלת אנימציה של כשלון בעקבות  התנגשות באויב 
//------------------------------------------------------------
void Enemies::playAnimation()
{
	m_level->handleAnimationExplosion();
}
//פונקציה האחראית על עדכון שעכשיו יש מצב כישלון 
//------------------------------------------------------------
void Enemies::updateFailure(bool b)
{
	m_level->updateFailure(b);
}
