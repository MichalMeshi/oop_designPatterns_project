#pragma once
#include <memory>
#include "Utilities.h"
#include <vector>
#include <utility>
#include "SettingsCommand.h"
//-----------------------------------------------
class Menu{
public:
	Menu(Display d) : m_View(d){ }
	virtual ~Menu() = 0 {}
	void addCellToVec(std::pair<std::unique_ptr<Command>, Display>&& p) { m_menu.emplace_back(std::move(p)); }
	virtual void run() = 0;
protected:
	std::vector <std::pair<std::unique_ptr<Command>, Display>> m_menu;
	Display m_View;
	void handleBoard();
	void handleMouseMove(sf::Vector2f placeOfMove);
	void handlePress(sf::Vector2f);
};