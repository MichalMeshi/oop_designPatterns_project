#include "GameController.h"
#include "InfoOfLevel.h"
void GameController::runTheGame()
{
	enum EndOfLevelCondition endLevelCondition;
	int curentLevel = 1;
	while (curentLevel <= LEVELS_AMOUNT )   //לטפל בזה...
	{
		m_window.create(sf::VideoMode({ WIDTH_WINDOW,HIGTH_WINDOW }), "Xonix");
	//	m_window.setFramerateLimit(FRAME_LIMIT_SPEED);
		//m_nameFile[LEVEL_NUMBER_INDEX] = char(curentLevel + 48);//מחשב בקלות את מספר השלב הנוכחי על פי קוד אסקי
		Level level(m_window, curentLevel, m_infoOfLevel.m_amountEnemiesInLevelMatrix[curentLevel]); //בשביל הסרגל של השלב
		endLevelCondition = level.runLevel();
		Graphics::getGraphics().getSoundVec()[CLOCK_SOUND]->pause();

		if (endLevelCondition == FAIL_LEVEL)
		{
			//m_window.close();להעביר לבסוף
			break;
		}

		else if (endLevelCondition == CLOSE)
			return;
		else if (endLevelCondition == FINISHLEVEL)
		{
			Graphics::getGraphics().getSoundVec()[WIN_SOUND]->play();
			m_levelUp.draw(m_window);
			m_window.display();
			sf::sleep(sf::Time(sf::seconds(3)));
			curentLevel++;
		}

	}

	//if(curentLevel<4)
	//	//תמונה של כשלון
	/*else*/ if(curentLevel==4)
		m_window.close();

	//	//תמונה של ניצחון

	//בכל מקרה, סגירת חלון
	m_window.close();
}
