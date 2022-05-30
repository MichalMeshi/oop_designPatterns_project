#include "GameController.h"
void GameController::runTheGame()
{
	enum EndOfLevelCondition endLevelCondition;
	int curentLevel = 1;
	while (curentLevel <= LEVELS_AMOUNT )   //���� ���...
	{
		m_window.create(sf::VideoMode({ WIDTH_WINDOW,HIGTH_WINDOW }), "Xonix");
	//	m_window.setFramerateLimit(FRAME_LIMIT_SPEED);
		//m_nameFile[LEVEL_NUMBER_INDEX] = char(curentLevel + 48);//���� ����� �� ���� ���� ������ �� �� ��� ����
		Level level(m_window, curentLevel); //����� ����� �� ����
		endLevelCondition = level.runLevel();
		if (endLevelCondition == FAIL_LEVEL)
		{
			m_window.close();
			break;
		}
		else if (endLevelCondition == CLOSE)
			return;
		else if (endLevelCondition == FINISHLEVEL)
			curentLevel++;
	}

	//if(curentLevel<4)
	//	//����� �� �����
	// ����� ����� 
	//	else if(curentLevel==4)
	//	//����� �� ������
	//����� �����
	// �� ���� ����� ���
	//	//������ ����� ������ �� �����
}
