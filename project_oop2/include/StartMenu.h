#pragma once
#include "NewGame.h"
#include "Menu.h"

class StartMenu:public Menu
{
public:
	StartMenu(GameController& ,sf::RenderWindow&);
	~StartMenu() {}
private:
};


//������ ������� �� ����� �� �����- ������ ����� ���.
//������ ���� �� ����� �� �� ����. 
//�� ������ - �����
//�� ���� ����� ��� ������