#include "Level.h"
Level::Level(sf::RenderWindow& window)
    :m_window(window), m_board(window)
{
   /* m_timeOutTxt.setFont(Graphics::getGraphics().getFont());
    m_timeOutTxt.setString("TIME-OUT");
    m_timeOutTxt.setPosition({ 150,90 });
    m_timeOutTxt.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    m_timeOutTxt.setCharacterSize(350);
    m_timeOutTxt.setColor(sf::Color::Black);*/
}
//---------------------------------
void Level::runLevel()
{
    m_window.setFramerateLimit(60);
    int dx = 0, dy = 0,x=0,y=0;
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_window.close();
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { dx = -1; dy = 0; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dx = 1; dy = 0; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { dx = 0; dy = -1; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { dx = 0; dy = 1; }

        x += dx;
        y += dy;

        if (x < 0) x = 0; if (x > 44) x = 44;
        if (y < 0) y = 0; if (y > 44) y = 44;
        if (m_board.checkIfPassedAlready(y,x))
            m_window.close();

        m_board.moveEnemies();
        m_board.handleSpaceBlockage(y,x,dx,dy);

        //בדיקת התנגשות של שחקן מול אויבים

        m_window.clear();
        m_board.draw(y,x);
        m_window.display();
    }
}