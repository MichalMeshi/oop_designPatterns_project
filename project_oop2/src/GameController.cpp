#include "GameController.h"
void GameController::runTheGame()
{
	enum EndOfLevelCondition endLevelCondition;
	int curentLevel = 1;
	while (curentLevel <= LEVELS_AMOUNT )   //לטפל בזה...
	{
		m_window.create(sf::VideoMode({ WIDTH_WINDOW,HIGTH_WINDOW }), "Xonix");
	//	m_window.setFramerateLimit(FRAME_LIMIT_SPEED);
		//m_nameFile[LEVEL_NUMBER_INDEX] = char(curentLevel + 48);//מחשב בקלות את מספר השלב הנוכחי על פי קוד אסקי
		Level level(m_window, curentLevel); //בשביל הסרגל של השלב
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
	//	//תמונה של כשלון
	// וטבלת שיאים 
	//	else if(curentLevel==4)
	//	//תמונה של ניצחון
	//וטבלת שיאים
	// או טבלת שיאים אחת
	//	//השהייה לחלון ולסגור את החלון
}
