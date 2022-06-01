#include "Level.h"
Level::Level(sf::RenderWindow& window, int curentLevel)
    :m_window(window), m_board(window, curentLevel), m_infoMenu(char(curentLevel+48), m_window)
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
    int gift_num = (rand() % 6) + 4;
    int rand_time = (rand() % 6) + 5;
    m_window.setFramerateLimit(60);
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
        if (m_board.checkIfPassedAlready())
            m_window.close();

        m_board.moveEnemies();
        m_board.handleSpaceBlockage();
        m_board.handleCreateGifts(gift_num, rand_time);
        
        //בדיקת התנגשות של שחקן מול אויבים

        m_window.clear();
        m_board.draw();
        m_infoMenu.drawInfoMenu();
        m_window.display();
    }
    return FINISHLEVEL; // זה סתם
}