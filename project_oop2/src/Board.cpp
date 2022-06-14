#include "Board.h"
#include "CollisionHandling.h"
#include "Level.h"

Board::Board(sf::RenderWindow& window, int curentLevel, int& percent)
	:m_window(window), m_player(Graphics::getGraphics().getTexture(PLAYER), sf::Vector2f(40, 40)),
	m_backgroundGame(Graphics::getGraphics().getTexture(SEA), {}, { WIDTH_WINDOW, HIGTH_WINDOW }), m_percentage(percent),
	m_crumbPic(Graphics::getGraphics().getTexture(CRUMB_ANIMATION), {}, {500,100}), m_crumbAnimation(m_crumbPic,500,100)
{
	m_matrix.resize(MATRIX_SIZE);
	clockForGifts.restart();
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			m_matrix[i].emplace_back(EMPTY);
			if (i == ZERO || j == ZERO || i == MATRIX_SIZE-1 || j == MATRIX_SIZE-1)
				m_matrix[i][j] = BLOCKED;
		}
	m_rec.setFillColor(sf::Color::White);
	m_rec.setPosition(BEGGINING_OF_BOARD_X, BEGGINING_OF_BOARD_Y);
	m_rec.setSize(sf::Vector2f(BOARD_GAME_LENGTH, BOARD_GAME_LENGTH));
}
//-----------------------------------------------
void Board::draw(std::vector<int> infoVec)
{
	
	m_backgroundGame.draw(m_window);
	m_window.draw(m_rec);
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			sf::RectangleShape rect(BOARD_GAME_CELL);
			rect.setPosition(j * BOARD_GAME_CELL_SIZE + BEGGINING_OF_BOARD_X, i * BOARD_GAME_CELL_SIZE + BEGGINING_OF_BOARD_Y);
			if (m_matrix[i][j] == EMPTY)
				rect.setTexture(&(Graphics::getGraphics().getTexture(infoVec[INDEX_OF_EMPTY])));
			if (m_matrix[i][j] == BLOCKED)
				rect.setTexture(&(Graphics::getGraphics().getTexture(infoVec[INDEX_OF_BLOCKED])));
			if (m_matrix[i][j] == MIDDLE)
				rect.setTexture(&(Graphics::getGraphics().getTexture(infoVec[INDEX_OF_MIDDLE])));
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
	for(auto& enemy: m_enemiesVec)
	{
		enemy->move(*this);
		if (m_matrix[enemy->getIndex().x][enemy->getIndex().y] == MIDDLE)
		{
			m_inFailure = true;
			isColide = true;
		}
	}
	for (auto& territoryEater : m_territoryEaterVec)
	{
		territoryEater->move(*this);
		if (m_matrix[territoryEater->getIndex().x][territoryEater->getIndex().y] == MIDDLE)
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
		m_player.setPlayerDx(ZERO);
		m_player.setPlayerDy(ZERO);

		for (int i = 0; i < m_enemiesVec.size() - (smartMonstersAmount + dombMonstersAmount); i++)
			floodFill(m_enemiesVec[i]->getIndex());
		for (int i = 0; i < m_territoryEaterVec.size(); i++)
			floodFill(m_territoryEaterVec[i]->getIndex());

		for (int i = 0; i < MATRIX_SIZE; i++)
			for (int j = 0; j < MATRIX_SIZE; j++)
			{
					if ((m_matrix[i][j] == MIDDLE && m_inFailure) || m_matrix[i][j] == AROUND_ENEMY)
						m_matrix[i][j] = EMPTY;
						
					else if ((m_matrix[i][j] == EMPTY || m_matrix[i][j] == MIDDLE) && !m_inFailure)
					{
						if (++m_blockCounter >= AMOUNT_FOR_ONE_PERCENT)
						{
							m_percentage++;
							m_blockCounter = ZERO;
						}
						m_matrix[i][j] = BLOCKED;

					}
			}
		m_inFailure = false;
	}

}
//----------------------------------------------------------
void Board::floodFill(sf::Vector2i v)
{
	if (v.x >= ZERO && v.x <= MATRIX_SIZE-1 && v.y >= ZERO && v.y <= MATRIX_SIZE-1 && m_matrix[v.x][v.y] == EMPTY) m_matrix[v.x][v.y] = AROUND_ENEMY;
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
		m_player.setPlayerDx(1);m_player.setPlayerDy(0);
		break;
	}
	case sf::Keyboard::Key::Left:
	{
		m_player.setPlayerDx(-1);m_player.setPlayerDy(0);
		break;
	}

	case sf::Keyboard::Key::Down:
	{
		m_player.setPlayerDx(0);m_player.setPlayerDy(1);
		break;
	}
	case sf::Keyboard::Key::Up:
	{
		m_player.setPlayerDx(0);m_player.setPlayerDy(-1);
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
	if ((!(i <= ZERO || i >= MATRIX_SIZE-1 || j <= ZERO || j >= MATRIX_SIZE - 1))
		&& (m_matrix[i][j] == BLOCKED || m_matrix[i][j] == MIDDLE)){
		if (--m_blockCounter <= ZERO)
		{
			m_percentage--;
			m_blockCounter = AMOUNT_FOR_ONE_PERCENT;
		}
		m_matrix[i][j] = EMPTY;
		handleAnimationCrumb(i,j);
	}
}
//---------------------------------------------------------
void Board::handleCollision()
{
	sf::Sound music(Graphics::getGraphics().getSound(GIFT_SOUND));
	Graphics::getGraphics().getSoundVec()[GIFT_SOUND] = music;

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
			Graphics::getGraphics().getSoundVec()[GIFT_SOUND].play();
		}
}
//-------------------------------------------------------------
bool Board::colide(Object& obj1, Object& obj2)const
{
	sf::FloatRect res;
	auto player = sf::FloatRect(obj2.getDisplay().getSprite().getGlobalBounds());
	return (player.intersects(obj1.getDisplay().getSprite().getGlobalBounds(),res));
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
void Board::unFreezeEnemies()
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
		m_giftsVec[i]->handleAnimation();
}
//-------------------------------------------------------------
void Board::handleAnimationCrumb(int i,int j)//לשים אולי באוביקט כזה
{
	sf::Vector2f pos;
	pos.x = 20*j+350-15;
	pos.y = 20*i+50-15;
	m_crumbPic.setPosition(pos);
	m_crumbAnimation.handleAnimation();
	//m_crumbPic.update(posAnimation.x,100);
	m_crumbPic.draw(m_window);
	m_window.display();
	/*posAnimation.x += 100;
	if (posAnimation.x == 500)
		posAnimation.x = 0;*/
}