#pragma once
#include "NewGame.h"
#include "Menu.h"

class StartMenu:public Menu
{
public:
	StartMenu();
	~StartMenu()=default;
private:
	GameController m_game;
};


//������ ������� �� ����� �� �����- ������ ����� ���.
//������ ���� �� ����� �� �� ����. 
//�� ������ - �����
//�� ���� ����� ��� ������