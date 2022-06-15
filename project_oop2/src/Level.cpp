#include "Level.h"
//---------------------------------
Level::Level(sf::RenderWindow& window, int curentLevel, std::vector<int> i)
    :m_window(window), m_board(window, curentLevel, m_percentage), m_timeForLevel((rand() % 30) + 35), m_infoMenu(char(curentLevel + 48),
        m_window, m_timeForLevel), m_infoOfLevel(i), m_explosionPic(Graphics::getGraphics().getTexture(EXPLOSION_ANIMATION), {350,50},{4500,900}), m_explosionAnimation(m_explosionPic,4500,900),
        m_levelUp(Graphics::getGraphics().getTexture(LEVEL_UP), sf::Vector2f(800, 500), sf::Vector2f(500, 150))
{
    m_board.createEnemiesInBoard(curentLevel, this, m_infoOfLevel);
    m_board.createTerritoryEnemiesInBoard(curentLevel, this, m_infoOfLevel);
    m_levelUp.setOrigin(250, 75);
}
//פוקנציה האחראית על ריצת כל שלב
//---------------------------------
enum EndOfLevelCondition Level::runLevel()
{
    sf::Clock clock;
    int rand_time = (rand() % 6) + 5;
    while (m_window.isOpen())
    {
        if (handleEvents() == CLOSE)
            return CLOSE;

        movesObjects();

        if (m_board.checkIfPassedAlready()) 
            handleFailure();
        m_board.handleCollision();

        m_board.handleSpaceBlockage();
        
        m_board.handleCreateGifts(m_gift_num, rand_time, this);

        handleTime(clock);

        if (m_infoOfLevel[LIFE_AMOUNT] < 0)
            return FAIL_LEVEL;
        drawing();
        if (handlePercentage() == FINISHLEVEL)
        {
            drawing();
            return FINISHLEVEL;
        }

    }
    return FINISHLEVEL; // זה סתם
}
//פונקציה המטפלת בלולאת האירועים 
//------------------------------------------------
enum EndOfLevelCondition Level::handleEvents()
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
    return JUST_FOR_VISUAL;//for visual
}
//פונקציה האחראית על כל מה שקשור לזמן של השלב
//------------------------------------------------
void Level::handleTime(sf::Clock& clock)
{
    if (int(m_timeForLevel - clock.getElapsedTime().asSeconds()) == 10)
        Graphics::getGraphics().getSoundVec()[CLOCK_SOUND]->play();
    if (float(m_timeForLevel - clock.getElapsedTime().asSeconds()) <= 0)
    {
        Graphics::getGraphics().getSoundVec()[CLOCK_SOUND]->pause();
        handleFailure();
        clock.restart();
    }
    m_infoMenu.setTimer(float(m_timeForLevel - clock.getElapsedTime().asSeconds()));

    if (m_clockForGift.getElapsedTime().asSeconds() >= 5)
    {
        m_board.unFreezeEnemies();
        m_board.setPlayer();
    }
}
//פונקציה האחראית על האחוזים שהשחקן כבש
//------------------------------------------------
enum EndOfLevelCondition Level::handlePercentage()
{
    m_infoMenu.setPercentage(m_percentage, m_infoOfLevel[PERCENTAGE]);
    if (m_percentage >= m_infoOfLevel[PERCENTAGE])
        return FINISHLEVEL;
    return JUST_FOR_VISUAL;
}
//פונקציה האחראית על כישלון של השחקן
//------------------------------------------------
void Level::handleFailure()
{
    --m_infoOfLevel[LIFE_AMOUNT]; 
    handleAnimationExplosion();
    m_board.setPlayerPositionToBegining();
    Graphics::getGraphics().getSoundVec()[FAILURE_SOUND]->play();
}
//פוקנציה האחראית על תזוזת האוביקטים במשחק
//------------------------------------------------
void Level::movesObjects()
{
    m_board.movePlayer();
    if (m_board.moveEnemies())  handleFailure();
}
//פונקציה האחראית על ההדפסה 
//------------------------------------------------
void Level::drawing()
{
    m_window.clear();
    m_board.draw(m_infoOfLevel);
    m_infoMenu.drawInfoMenu(m_infoOfLevel[LIFE_AMOUNT]);
    if (m_percentage >= m_infoOfLevel[PERCENTAGE])
        m_levelUp.draw(m_window);
    m_window.display();
}
//פונקציה האחראית על אנימצית ההתפוצצות 
//------------------------------------------------
void Level::handleAnimationExplosion()
{
    for (int i = 0; i < 5; i++)
    {
        m_window.clear();
        drawing();
        m_explosionAnimation.handleAnimation();
        m_explosionPic.draw(m_window);
        m_window.display();
    }
}
