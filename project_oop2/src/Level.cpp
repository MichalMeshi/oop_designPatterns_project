#include "Level.h"
Level::Level(sf::RenderWindow& window, int curentLevel)
    :m_window(window), m_board(window), m_infoMenu(char(curentLevel), m_window)
{
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
    m_window.setFramerateLimit(60);
    int dx = 0, dy = 0, x = 0, y = 0;
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
                m_board.setDirection(event.key.code, dx, dy);
                break;
            }
            }
        }
        m_board.movePlayer(x, y, dx, dy);
        if (m_board.checkIfPassedAlready(y, x))
            m_window.close();

        m_board.moveEnemies();
        m_board.handleSpaceBlockage(y, x, dx, dy);

        //בדיקת התנגשות של שחקן מול אויבים

        m_window.clear();
        m_board.draw(y, x);
        m_window.display();
    }
    return FINISHLEVEL; // זה סתם
}