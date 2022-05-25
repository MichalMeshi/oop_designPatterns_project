#pragma once
//---------------------------------------------------------------------------------------
#include<vector>
#include "Utilities.h"
#include <SFML/Graphics.hpp>
//------------------------------
class Graphics {
public:
	static Graphics& getGraphics() {
		static Graphics m_graphics;
		return m_graphics;
	}
	~Graphics() = default;
	sf::Font& getFont() { return m_font; }//Cant be const
	sf::Texture& getTexture(int i) { return m_tex[i]; }//Cant be const
private:
	Graphics();
	Graphics(const Graphics&) = default;
	std::vector<sf::Texture> m_tex;
	std::vector<sf::Text> m_text;
	sf::Font m_font;
};

