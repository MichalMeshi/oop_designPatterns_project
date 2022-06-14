#pragma once
class ImmunePlayer:public Player
{
public:
	ImmunePlayer( int x,int y,int dx,int dy)
		: Player(Graphics::getGraphics().getTexture(IMMUNE_PLAYER), { 40,40 }, x, y, dx, dy) {}
	
	private:
	
};