#include "Board.h"
#include "CollisionHandling.h"

Board::Board(sf::RenderWindow& window, int curentLevel, int& percent)
	:m_window(window), m_player(Graphics::getGraphics().getTexture(PLAY), sf::Vector2f(40, 40)),
	m_backgroundGame(Graphics::getGraphics().getTexture(SEA), {}, { WIDTH_WINDOW, HIGTH_WINDOW }), m_percentage(percent)
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
}
//-----------------------------------------------
void Board::draw()
{
	m_backgroundGame.draw(m_window);
	m_window.draw(m_rec);
	for (int i = 0; i < 45; i++)
		for (int j = 0; j < 45; j++)
		{
			sf::RectangleShape rect({ 20,20 });
			rect.setPosition(j * 20 + 350, i * 20 + 50);
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
	for (int i = 0; i < m_territoryEaterVec.size(); i++)
		m_territoryEaterVec[i]->draw(m_window);
	for (int i = 0; i < m_giftsVec.size(); i++)
		m_giftsVec[i]->draw(m_window);
}
//------------------------------------------------
bool Board::checkIfPassedAlready()
{
	if (m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] == MIDDLE) {
		m_inFailure = true;
		return true;
	}
	if (m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] == EMPTY) m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] = MIDDLE;
	return false;
}
//-------------------------------------------------
bool Board::moveEnemies()
{
	bool isColide = false;
	for (int i = 0; i < m_enemiesVec.size(); i++)
	{
		m_enemiesVec[i]->move(*this);
		if (m_matrix[m_enemiesVec[i]->getIndex().x][m_enemiesVec[i]->getIndex().y] == MIDDLE)
		{
			m_inFailure = true;
			isColide = true;
		}
	}
	for (int i = 0; i < m_territoryEaterVec.size(); i++)
	{
		m_territoryEaterVec[i]->move(*this);
		if (m_matrix[m_territoryEaterVec[i]->getIndex().x][m_territoryEaterVec[i]->getIndex().y] == MIDDLE)
		{
			m_inFailure = true;
			isColide = true;
		}
	}
	return isColide;
}
//-------------------------------------------------
void Board::handleSpaceBlockage(int smartMonstersAmount, int dombMonstersAmount)
{
	if (m_matrix[m_player.getPlayerYpos()][m_player.getPlayerXpos()] == BLOCKED)
	{
		m_player.setPlayerDx(0);
		m_player.setPlayerDy(0);

		for (int i = 0; i < m_enemiesVec.size() - (smartMonstersAmount + dombMonstersAmount); i++)//להוציא מכאן את החכמים והטפשים..
			floodFill(m_enemiesVec[i]->getIndex());
		for (int i = 0; i < m_territoryEaterVec.size(); i++)
			floodFill(m_territoryEaterVec[i]->getIndex());

		for (int i = 0; i < 45; i++)
			for (int j = 0; j < 45; j++)
			{
				/*if (m_matrix[i][j] == -1)
					m_matrix[i][j] = EMPTY;
				else
				{*/
					if ((m_matrix[i][j] == 2 && m_inFailure) || m_matrix[i][j] == -1)
						m_matrix[i][j] = EMPTY;
						
					else if ((m_matrix[i][j] == EMPTY || m_matrix[i][j] == 2) && !m_inFailure)
					{
						if (++m_blockCounter == 21)
						{
							m_percentage++;
							m_blockCounter = 0;
						}
						m_matrix[i][j] = BLOCKED;

					}
			/*	}*/
			}
		m_inFailure = false;
	}

}
//----------------------------------------------------------
void Board::floodFill(sf::Vector2i v)
{
	if (v.x >= 0 && v.x <= 44 && v.y >= 0 && v.y <= 44 && m_matrix[v.x][v.y] == EMPTY) m_matrix[v.x][v.y] = -1;
	if (((v.x - 1) >= 0) && v.y >= 0 && v.y <= 44 && m_matrix[v.x - 1][v.y] == EMPTY) floodFill(sf::Vector2i(v.x - 1, v.y));
	if (((v.x + 1) <= 44) && v.y >= 0 && v.y <= 44 && m_matrix[v.x + 1][v.y] == EMPTY) floodFill(sf::Vector2i(v.x + 1, v.y));
	if (((v.y - 1) >= 0) && v.x >= 0 && v.x <= 44 && m_matrix[v.x][v.y - 1] == EMPTY) floodFill(sf::Vector2i(v.x, v.y - 1));
	if (((v.y + 1) <= 44) && v.x >= 0 && v.x <= 44 && m_matrix[v.x][v.y + 1] == EMPTY) floodFill(sf::Vector2i(v.x, v.y + 1));
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
		m_player.setRotation(270);
		m_player.setPlayerDx(1);
		m_player.setPlayerDy(0);
		break;
	}
	case sf::Keyboard::Key::Left:
	{
		m_player.setRotation(90);
		m_player.setPlayerDx(-1);
		m_player.setPlayerDy(0);
		break;
	}

	case sf::Keyboard::Key::Down:
	{
		m_player.setRotation(0);
		m_player.setPlayerDx(0);
		m_player.setPlayerDy(1);
		break;
	}
	case sf::Keyboard::Key::Up:
	{
		m_player.setRotation(180);
		m_player.setPlayerDx(0);
		m_player.setPlayerDy(-1);
		break;
	}
	default:
		return;
	}
}
//--------------------------------------------
void Board::handleCreateGifts(int& gift_num, int rand_time, Level* l)
{
	if (clockForGifts.getElapsedTime().asSeconds() >= rand_time && gift_num != 0)
	{
		m_giftsVec.emplace_back(GiftFactory::createGift(l));
		gift_num--;
		clockForGifts.restart();
	}
}
sf::Vector2f Board::findDirectionToMove(int x, int y)
{
	sf::Vector2f pos = { 0,0 };

	if (m_player.isRight(x))
		pos.x = 1;
	else if (m_player.isLeft(x))
		pos.x = -1;

	else if (m_player.isUp(y))
		pos.y = -1;
	else if (m_player.isDown(y))
		pos.y = 1;
	if (m_player.isUp(y) && m_player.isRight(x))
	{
		pos.x = 1;
		pos.y = 0;
	}
	return pos;
}
//--------------------------------------------------------
void Board::eatCellInMatrix(int i, int j)
{
	if ((!(i <= 0 || i >= 44 || j <= 0 || j >= 44)) 
		&& (m_matrix[i][j] == BLOCKED || m_matrix[i][j] == MIDDLE))
	{
		if (--m_blockCounter == 0)
		{
			m_percentage--;
			m_blockCounter = 21;
		}
		m_matrix[i][j] = EMPTY;
	}
}
//---------------------------------------------------------
void Board::handleCollision()
{

	for (auto& enemy : m_enemiesVec)
		if (colide(*enemy, m_player))
		{
			processCollision(*enemy, m_player);
			m_inFailure = true;
		}
	for (int i = 0; i < m_giftsVec.size(); i++)
		if (colide(*m_giftsVec[i], m_player))
		{
			processCollision(*m_giftsVec[i], m_player);
			m_giftsVec.erase(m_giftsVec.begin() + i);
		}
}
//-------------------------------------------------------------
bool Board::colide(Object& obj1, Object& obj2)
{
	sf::FloatRect res;
	return (obj1.getDisplay().getSprite().getGlobalBounds().contains(obj2.getDisplay().getSprite().getPosition()));
	//auto player = sf::FloatRect(obj2.getDisplay().getSprite().getGlobalBounds());
	//return (player.intersects(obj1.getDisplay().getSprite().getGlobalBounds(),res));
}
//-------------------------------------------------------------
void Board::createEnemiesInBoard(int curentLevel, Level* l, std::vector<int> vec)
{
	m_enemiesVec = EnemyFactory::createEnemies(curentLevel, l, vec);
}
//-------------------------------------------------------------
void Board::createTerritoryEnemiesInBoard(int curentLevel, Level* l, std::vector<int> vec)
{
	m_territoryEaterVec = EnemyFactory::createTerritoryEaters(curentLevel, l, vec);
}
//-------------------------------------------------------------
void Board::freezeEnemies()
{
	for (auto& enemy : m_enemiesVec)
		enemy->freeze();
	for (auto& enemy : m_territoryEaterVec)
		enemy->freeze();
}
//-------------------------------------------------------------
void Board::unFreeze()
{
	for (auto& enemy : m_enemiesVec)
		enemy->unFreeze();
	for (auto& enemy : m_territoryEaterVec)
		enemy->unFreeze();
}
//-------------------------------------------------------------
void Board::rotateGifts()
{
	for (int i = 0; i < m_giftsVec.size(); i++)
		m_giftsVec[i]->rotate();
}
