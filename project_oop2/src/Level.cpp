#include "Level.h"
Level::Level(sf::RenderWindow& window, int curentLevel, std::vector<int> i)
    :m_window(window), m_board(window, curentLevel, m_percentage), m_timeForLevel((rand() % 30) + 35), m_infoMenu(char(curentLevel + 48),
        m_window, m_timeForLevel),  m_infoOfLevel(i)
{
    m_board.createEnemiesInBoard(curentLevel, this, m_infoOfLevel);
    m_board.createTerritoryEnemiesInBoard(curentLevel, this, m_infoOfLevel);
    /* m_timeOutTxt.setFont(Graphics::getGraphics().getFont());
     m_timeOutTxt.setString("TIME-OUT");
     m_timeOutTxt.setPosition({ 150,90 });
     m_timeOutTxt.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
     m_timeOutTxt.setCharacterSize(350);
     m_timeOutTxt.setColor(sf::Color::Black);*/

     //בתוך כל שלב, גם לשנות את הטיימר באינפורמיישן

}
//---------------------------------
enum EndOfLevelCondition Level::runLevel()
{
    sf::Clock clock;
    int gift_num = (rand() % 6) + 4;
    int rand_time = (rand() % 6) + 5;
    m_window.setFramerateLimit(1000);
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                m_window.close();
                return CLOSE;
            }
            case sf::Event::KeyPressed:
            {
                m_board.setDirection(event.key.code);
                break;
            }
            }
        }
        m_board.movePlayer();

        if (m_board.moveEnemies())
        {
            m_infoOfLevel[LIFE_AMOUNT]--;
            m_board.setPlayerPositionToBegining();
        }
        if (m_board.checkIfPassedAlready())
        {
            m_infoOfLevel[LIFE_AMOUNT]--;
            m_board.setPlayerPositionToBegining();
        }
        m_board.handleSpaceBlockage(m_infoOfLevel[SMART_MONSTER], m_infoOfLevel[DOMB_MONSTER]);
   
        m_board.handleCreateGifts(gift_num, rand_time, this);
        if (float(m_timeForLevel - clock.getElapsedTime().asSeconds()) <= 0)
        {
            m_infoOfLevel[LIFE_AMOUNT]--;
            m_board.setPlayerPositionToBegining();
            clock.restart();
        }
        if (m_percentage >= m_infoOfLevel[PERCENTAGE])
        {
            return FINISHLEVEL;
        }
        m_infoMenu.setTimer(float(m_timeForLevel - clock.getElapsedTime().asSeconds()));
        m_infoMenu.setPercentage(m_percentage);/////
        m_board.handleCollision();
        if (m_infoOfLevel[LIFE_AMOUNT] < 0)
            return FAIL_LEVEL;
        if (m_clockForGift.getElapsedTime().asSeconds() >= 5)
            m_board.unFreeze();
        m_window.clear();
        m_board.draw();
        m_infoMenu.drawInfoMenu(m_infoOfLevel[LIFE_AMOUNT]);
        m_window.display();
    }
    return FINISHLEVEL; // זה סתם
}