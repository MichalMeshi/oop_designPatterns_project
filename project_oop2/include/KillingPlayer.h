#pragma once
class KillingPlayer :public Player
{
public:
	KillingPlayer(int x, int y, int dx, int dy)
		: Player(Graphics::getGraphics().getTexture(KILLING_PLAYER), PLAYER_SPRITE_SIZE, x, y, dx, dy) {}
	~KillingPlayer() = default;
};
