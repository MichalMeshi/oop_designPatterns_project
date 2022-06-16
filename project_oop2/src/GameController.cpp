#include "GameController.h"
#include "InfoOfLevel.h"

//������� ������� �� ����� �����
//----------------------------------------------------------------
void GameController::runTheGame()
{
	int curentLevel = FIRST_LEVEL;
	runGameLevels(curentLevel);
	if (curentLevel < LEVELS_AMOUNT + 1)
		m_gameOver.draw(m_window);
	handleWindow();
}
//----------------------------------------------------------------
//������� ������� �� ������ ������ �� ����� ����� �����
void GameController::handleWindow()
{
	m_window.display();
	sf::sleep(sf::Time(sf::seconds(THREE_SECONDS)));
	m_window.close();
}
//----------------------------------------------------------------
//������� ������ �� ���� �����
void GameController::runGameLevels(int& curentLevel)
{
	enum EndOfLevelCondition endLevelCondition;
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
			sf::sleep(sf::Time(sf::seconds(THREE_SECONDS)));
			curentLevel++;
		}
	}
}

