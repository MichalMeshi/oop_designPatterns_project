#include "Level.h"
Level::Level(sf::RenderWindow& window, int curentLevel, std::vector<int> i)
    :m_window(window), m_board(window, curentLevel, m_percentage), m_timeForLevel((rand() % 30) + 35), m_infoMenu(char(curentLevel + 48),
        m_window, m_timeForLevel), m_infoOfLevel(i), m_explosionPic(Graphics::getGraphics().getTexture(EXPLOSION_ANIMATION), {350,50},{4500,900}), m_explosionAnimation(m_explosionPic,4500,900)
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
        if (m_board.moveEnemies()) { reduceLife(); }
        if (m_board.checkIfPassedAlready()) { reduceLife();}
        m_board.handleSpaceBlockage(m_infoOfLevel[SMART_MONSTER], m_infoOfLevel[DOMB_MONSTER]);

        m_board.handleCreateGifts(gift_num, rand_time, this);
        m_board.rotateGifts();
        if (int(m_timeForLevel - clock.getElapsedTime().asSeconds()) == 10)
            Graphics::getGraphics().getSoundVec()[CLOCK_SOUND]->play();
        if (float(m_timeForLevel - clock.getElapsedTime().asSeconds()) <= 0)
        {
            Graphics::getGraphics().getSoundVec()[CLOCK_SOUND]->pause();
            reduceLife();
            clock.restart();
        }
        if (m_percentage >= m_infoOfLevel[PERCENTAGE])
            return FINISHLEVEL;
        m_infoMenu.setTimer(float(m_timeForLevel - clock.getElapsedTime().asSeconds()));
        m_infoMenu.setPercentage(m_percentage, m_infoOfLevel[PERCENTAGE]);
        m_board.handleCollision();

        if (m_infoOfLevel[LIFE_AMOUNT] < 0)
        {
            return FAIL_LEVEL;
        }
        if (m_clockForGift.getElapsedTime().asSeconds() >= 5)
        {
            m_board.unFreezeEnemies();
            m_board.setPlayer();
        }
        m_window.clear();
        drawing();
        m_window.display();
    }
    return FINISHLEVEL; // זה סתם
}
void Level::reduceLife()
{
    --m_infoOfLevel[LIFE_AMOUNT]; 
    handleAnimationExplosion();
    m_board.setPlayerPositionToBegining();
    Graphics::getGraphics().getSoundVec()[FAILURE_SOUND]->play();
}
void Level::drawing()
{
    m_board.draw(m_infoOfLevel);
    m_infoMenu.drawInfoMenu(m_infoOfLevel[LIFE_AMOUNT]);
}

void Level::handleAnimationExplosion()
{
  /*  m_animationPos.x = 0;
    m_animationPos.y = 0;*/
    for (int i = 0; i < 5; i++)
    {
        m_window.clear();
        drawing();
        m_explosionAnimation.handleAnimation();
       // m_explosionPic.update(m_animationPos.x, 900);
        m_explosionPic.draw(m_window);
        m_window.display();
       // m_animationPos.x += 900;
    }
}
