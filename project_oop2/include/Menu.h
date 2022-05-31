#pragma once
#include <memory>
#include "Utilities.h"
#include <vector>
#include <utility>
#include "Settings.h"
class Menu
{
public:
	//Menu(sf::VideoMode v,std::string s,Display d) :m_window(v,s),m_View(d) {}
	Menu(sf::RenderWindow& window,Display d) :m_window(window),m_View(d) {}
	~Menu() = default;
	void addCellToVec(std::pair<std::unique_ptr<Command>, Display>&& p) { m_menu.emplace_back(std::move(p)); }
	void run();
protected:
	sf::RenderWindow& m_window;
	std::vector <std::pair<std::unique_ptr<Command>, Display>> m_menu;
	Display m_View;
	void handleMouseMove(sf::Vector2f placeOfMove);
	void handlePress(sf::Vector2f);
	virtual void handleBoard();
};
