#include "GameController.h"
void GameController::runTheGame()
{
	int curentLevel = 1;
	while (curentLevel < 2)
	{
		m_window.create(sf::VideoMode({ WIDTH_WINDOW,HIGTH_WINDOW }), "Xonix");
	//	m_window.setFramerateLimit(FRAME_LIMIT_SPEED);
		//m_nameFile[LEVEL_NUMBER_INDEX] = char(curentLevel + 48);//מחשב בקלות את מספר השלב הנוכחי על פי קוד אסקי
		Level level(m_window);
		level.runLevel();
		//if (level.runLevels() == TIMEOVER)
		//	m_window.close();
		//else if (level.runLevels() == CLOSE)
		//	return;
		//else if (level.runLevels() == FINISHLEVEL)
		//	//הצגת טבלת שיאים
			curentLevel++;
	}
	//if(curentLevel<4)
	//	//תמונה של כשלון
	//	else if(curentLevel==4)
	//	//תמונה של ניצחון

	//	//השהייה לחלון ולסגור את החלון
}
