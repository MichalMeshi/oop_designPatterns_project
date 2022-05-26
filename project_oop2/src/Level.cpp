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
                return;
            }
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    m_window.close();
                    break;
                }
                else
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

        //����� ������� �� ���� ��� ������

        m_window.clear();
        m_board.draw(y, x);
        m_window.display();
    }
}