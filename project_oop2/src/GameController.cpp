#include "GameController.h"
#include "InfoOfLevel.h"
void GameController::runTheGame()
{
	enum EndOfLevelCondition endLevelCondition;
	int curentLevel = 1;
	while (curentLevel <= LEVELS_AMOUNT)
	{
		m_window.create(sf::VideoMode({ WIDTH_WINDOW,HIGTH_WINDOW }), "Xonix");
		Level level(m_window, curentLevel, m_infoOfLevel.m_amountEnemiesInLevelMatrix[curentLevel]); 
		endLevelCondition = level.runLevel();
		Graphics::getGraphics().getSoundVec()[CLOCK_SOUND]->pause();

		if (endLevelCondition == FAIL_LEVEL)
			break;
		else if (endLevelCondition == CLOSE)
			return;
		else if (endLevelCondition == FINISHLEVEL)
		{
			Graphics::getGraphics().getSoundVec()[WIN_SOUND]->play();
			sf::sleep(sf::Time(sf::seconds(3)));
			curentLevel++;
		}
	}

	if (curentLevel < 4)
	{
		m_gameOver.draw(m_window);
		m_window.display();
		sf::sleep(sf::Time(sf::seconds(3)));
	}
	else if (curentLevel == 4)
	{
		m_winGame.draw(m_window);
		m_window.display();
		sf::sleep(sf::Time(sf::seconds(3)));
	}

	m_window.close();
}
