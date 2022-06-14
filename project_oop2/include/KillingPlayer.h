#pragma once
class KillingPlayer :public Player
{
public:
	KillingPlayer(int x, int y, int dx, int dy)
		: Player(Graphics::getGraphics().getTexture(KILLING_PLAYER), { 40,40 }, x, y, dx, dy) {}

private:

};
