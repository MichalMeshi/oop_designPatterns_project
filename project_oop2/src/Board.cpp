#include "Board.h"
#include "Enemies.h"

Board::Board(sf::RenderWindow& window,int curentLevel)
	:m_amountEnemiesInLevelMatrix(),m_window(window),m_player(Graphics::getGraphics().getTexture(PLAY), sf::Vector2f(20, 20)),
	m_backgroundGame(Graphics::getGraphics().getTexture(SEA), {}, { WIDTH_WINDOW, HIGTH_WINDOW })
{

	m_matrix.resize(45);
	clockForGifts.restart();
	for (int i = 0; i < 45; i++)
		for (int j = 0; j < 45; j++)
		{
			m_matrix[i].emplace_back(EMPTY);

			if (i == 0 || j == 0 || i == 44 || j == 44)
				m_matrix[i][j] = BLOCKED;
		}

	m_rec.setFillColor(sf::Color::White);
	m_rec.setPosition(350, 50);
	m_rec.setSize(sf::Vector2f(900, 900));
	m_enemiesVec = EnemyFactory::createEnemies(curentLevel);
}
void Board::draw()
{
	m_backgroundGame.draw(m_window);
	m_window.draw(m_rec);
	for (int i = 0; i < 45; i++)
		for (int j = 0; j < 45; j++)
		{
			sf::RectangleShape rect({ 20,20 });
			rect.setPosition(j*20+350,i*20+50);
			if (m_matrix[i][j] == EMPTY)
				rect.setFillColor(sf::Color::White);
			if (m_matrix[i][j] == BLOCKED)
				rect.setFillColor(sf::Color::Black);
			if (m_matrix[i][j] == MIDDLE)
				rect.setFillColor(sf::Color::Green);
			m_window.draw(rect);
		}
	m_player.draw(m_window);
	for (int i = 0; i < m_enemiesVec.size(); i++)
		m_enemiesVec[i]->draw(m_window);
	for (int i = 0; i < m_giftsVec.size(); i++)
		m_giftsVec[i]->draw(m_window);
}
//------------------------------------------------
bool Board::checkIfPassedAlready()
{
	if (m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] == MIDDLE)return true;
	if (m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] == EMPTY) m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] = MIDDLE;
	return false;
}
//-------------------------------------------------
void Board::moveEnemies()
{
	for (int i = 0; i < m_enemiesVec.size(); i++)
		m_enemiesVec[i]->move(*this);

}
//-------------------------------------------------
void Board::handleSpaceBlockage()
{
	if (m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] == BLOCKED)
	{
		m_player.setPlayerDx(0);
		m_player.setPlayerDy(0);

		for (int i = 0; i < m_enemiesVec.size()-1; i++)
			floodFill(m_enemiesVec[i]->getIndex());

		for (int i = 0; i < 45; i++)
			for (int j = 0; j < 45; j++)
				if (m_matrix[i][j] == -1) m_matrix[i][j] = 0;
				else
				{
					m_matrix[i][j] = 1;
					if (++m_blockCounter == 21)
					{
						m_percentage++;
						m_blockCounter = 0;
					}
				}
	}
}
//----------------------------------------------------------
void Board::floodFill(sf::Vector2i v)
{
	if (m_matrix[v.x][v.y] == 0) m_matrix[v.x][v.y] = -1;
	if (m_matrix[v.x - 1][v.y] == 0) floodFill(sf::Vector2i(v.x - 1, v.y));
	if (m_matrix[v.x + 1][v.y] == 0) floodFill(sf::Vector2i(v.x + 1, v.y));
	if (m_matrix[v.x][v.y - 1] == 0) floodFill(sf::Vector2i(v.x, v.y - 1));
	if (m_matrix[v.x][v.y + 1] == 0) floodFill(sf::Vector2i(v.x, v.y + 1));
}
//------------------------------------------------------------
void Board::movePlayer()
{
	m_player.moveP();
}
//------------------------------------------------------------
void Board::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Right:
	{ 
		m_player.setPlayerDx(1);
		m_player.setPlayerDy(0);
		break;
	 }
	case sf::Keyboard::Key::Left:
	{
		m_player.setPlayerDx(-1);
		m_player.setPlayerDy(0);
		break;
	}

	case sf::Keyboard::Key::Down:
	{
		m_player.setPlayerDx(0);
		m_player.setPlayerDy(1);
		break;
	}
	case sf::Keyboard::Key::Up:
	{
		m_player.setPlayerDx(0);
		m_player.setPlayerDy(-1);
		break;
	}
	default:
		return;
	}
}
//--------------------------------------------
void Board::handleCreateGifts(int &gift_num, int rand_time)
{
	if (clockForGifts.getElapsedTime().asSeconds() >= rand_time && gift_num != 0)
	{
		m_giftsVec.emplace_back(GiftFactory::createGift());
		gift_num--;
		clockForGifts.restart();
	}
}
sf::Vector2f Board::findDirectionToMove(int x,int y)
{


	//NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	sf::Vector2f pos={0,0};

	if (m_player.isRight(x))
		pos.x = 1;
	else if (m_player.isLeft(x))
		pos.x = -1;

	else if(m_player.isUp(y))
		pos.y = -1;
	else if (m_player.isDown(y))
		pos.y = 1;
	if(m_player.isUp(y) && m_player.isRight(x))
	{
		pos.x = 1;
		pos.y = 0;
	}
	
	return pos;

}

