#include "GameController.h"
void GameController::runTheGame()
{
	int curentLevel = 1;
	while (curentLevel < 2)
	{
		m_window.create(sf::VideoMode({ WIDTH_WINDOW,HIGTH_WINDOW }), "Xonix");
	//	m_window.setFramerateLimit(FRAME_LIMIT_SPEED);
		//m_nameFile[LEVEL_NUMBER_INDEX] = char(curentLevel + 48);//���� ����� �� ���� ���� ������ �� �� ��� ����
		Level level(m_window);
		level.runLevel();
		//if (level.runLevels() == TIMEOVER)
		//	m_window.close();
		//else if (level.runLevels() == CLOSE)
		//	return;
		//else if (level.runLevels() == FINISHLEVEL)
		//	//���� ���� �����
			curentLevel++;
	}
	//if(curentLevel<4)
	//	//����� �� �����
	//	else if(curentLevel==4)
	//	//����� �� ������

	//	//������ ����� ������ �� �����
}
