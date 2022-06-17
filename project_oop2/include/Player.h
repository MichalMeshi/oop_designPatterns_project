#pragma once
#include "Object.h"
//-----------------------------------------------
class Player :public Object{
public:
	Player(sf::Texture& t, sf::Vector2f f, int x, int y, int dx, int dy);
	Player(sf::Texture& t, sf::Vector2f f) :Player(t,f,0,0,0,0){}
	Player(int dx, int dy) :Player(Graphics::getGraphics().getTexture(PLAYER), { 40,40 },0,0,dx,dy){}
	Player(int x,int y,int dx, int dy) :Player(Graphics::getGraphics().getTexture(PLAYER), { 40,40 }, x, y, dx, dy) {}
	~Player() {}
	void move();
	int getPlayerXpos()const { return m_x; }
	int getPlayerYpos()const { return m_y; }
	int getPlayerDx()const { return m_dx; }
	int getPlayerDy()const { return m_dy; }
	void setPlayerDx(int x) {  m_dx= x; }
	void setPlayerDy(int y) {  m_dy=y; }
	const sf::Texture* getTexture() { return (m_display.getTexture()); }
	void setPlayerPosition(sf::Vector2f v) { m_x = v.x; m_y = v.y; }
	bool isRight(int x)const;
	bool isUp(int y)const;
	bool isLeft(int y)const;
	bool isDown(int y)const;
	void setTexture(sf::Texture& t) { m_display.setTexture(t); }
protected:
	int m_x,  m_y, m_dx,  m_dy;
};