#include "Board.h"
#include "Enemies.h"

Board::Board(sf::RenderWindow& window,int curentLevel)
	:m_window(window),m_player(Graphics::getGraphics().getTexture(PLAY), sf::Vector2f(20, 20)),
	m_backgroundGame(Graphics::getGraphics().getTexture(SEA), {}, { WIDTH_WINDOW, HIGTH_WINDOW })
{
	//std::vector<int> rows(45);
	/*std::vector< std::vector<int>> vec;
	vec.resize(45);
	m_matrix = vec;*/

	
	clockForGifts.restart();
	for (int i = 0; i < 45; i++)
		for (int j = 0; j < 45; j++)
		{
			//m_matrix[i].emplace_back(EMPTY);

			if (i == 0 || j == 0 || i == 44 || j == 44)
				m_matrix[i][j] = BLOCKED;
		}

	m_rec.setFillColor(sf::Color::White);
	m_rec.setPosition(350, 50);
	m_rec.setSize(sf::Vector2f(900, 900));
	m_enemiesVec = EnemyFactory::createEnemies(curentLevel);
//להגריל מספר לשלב, ואז להגריל זמן, כל פעם שהזמן הזה עובר, להגריל עוד מתנה
	//עד שהוגרלו כולם.
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
	if (m_matrix[y][x] == MIDDLE)return true;
	if (m_matrix[y][x] == EMPTY) m_matrix[y][x] = MIDDLE;
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
	if (m_matrix[y][x] == BLOCKED)
	{
		dx = dy = 0;
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
	m_player.moveP( x, y, dx, dy);
}
//------------------------------------------------------------
void Board::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Right:
	{ dx = 1; dy = 0;  break; }
	case sf::Keyboard::Key::Left:
	{  dx = -1; dy = 0;  break; }
	case sf::Keyboard::Key::Down:
	{dx = 0; dy = 1;  break; }
	case sf::Keyboard::Key::Up:
	{dx = 0; dy = -1; break; }
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

