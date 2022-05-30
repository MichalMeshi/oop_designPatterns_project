#include "Board.h"
#include "EnemyFactory.h"
#include "GiftFactory.h"

Board::Board(sf::RenderWindow& window,int curentLevel)
	:m_window(window),m_player(Graphics::getGraphics().getTexture(PLAY), sf::Vector2f(350, 50), sf::Vector2f(30, 30)),
	m_backgroundGame(Graphics::getGraphics().getTexture(SEA), {}, { WIDTH_WINDOW, HIGTH_WINDOW })
{
	for (int i = 0; i < 45; i++)
		for (int j = 0; j < 45; j++)
			if (i == 0 || j == 0 || i == 44 || j == 44)
				m_matrix[i][j] = BLOCKED;
	m_rec.setFillColor(sf::Color::White);
	m_rec.setPosition(350, 50);
	m_rec.setSize(sf::Vector2f(900, 900));
	m_enemiesVec.emplace_back(EnemyFactory::createEnemy(Graphics::getGraphics().getTexture(INSTRUCTIONS), sf::Vector2f(500, 300), sf::Vector2f(30, 30), SMART_MOVE, MOVE_TO_UNBLOCKED));

	int num;
	switch (curentLevel)
	{
	case 1:
	{
		num = (rand() % 4) + 1;
		creatSimpleEnemies(num);
		//createGifts(num);
		m_enemiesVec.emplace_back(EnemyFactory::createEnemy(Graphics::getGraphics().getTexture(SEA), sf::Vector2f(500, 300), sf::Vector2f(30, 30), SIMPLE_MOVE, MOVE_TO_BLOCKED));
		break;
	}
	case 2:
	{
		num = (rand() % 4) + 2;
		creatSimpleEnemies(num);
		//createGifts(num);
		m_enemiesVec.emplace_back(EnemyFactory::createEnemy(Graphics::getGraphics().getTexture(SEA), sf::Vector2f(500, 300), sf::Vector2f(30, 30), SIMPLE_MOVE, MOVE_TO_BLOCKED));
		// לייצר אוכל שטחים פה
		break;

	}
	case 3:
	{
		num = (rand() % 4) + 3;
		creatSimpleEnemies(num);
		//createGifts(num);
		m_enemiesVec.emplace_back(EnemyFactory::createEnemy(Graphics::getGraphics().getTexture(SEA), sf::Vector2f(500, 300), sf::Vector2f(30, 30), SIMPLE_MOVE, MOVE_TO_BLOCKED));
		m_enemiesVec.emplace_back(EnemyFactory::createEnemy(Graphics::getGraphics().getTexture(SEA), sf::Vector2f(500, 300), sf::Vector2f(30, 30), SMART_MOVE, MOVE_TO_BLOCKED));
		//אוכל שטחים חכם אולי
		break;
	}
	default:
		break;
	}
}
//------------------------------------------
void Board::creatSimpleEnemies(int num)
{
	for (int i = 1; i <= num; i++)
		m_enemiesVec.emplace_back(EnemyFactory::createEnemy(Graphics::getGraphics().getTexture(INSTRUCTIONS), sf::Vector2f(500, 300), sf::Vector2f(30, 30), SIMPLE_MOVE, MOVE_TO_UNBLOCKED));
}
//------------------------------------------
void Board::createGifts(int num)
{
	for (int i = 0; i <= num; i++)
		m_giftsVec.emplace_back(GiftFactory::createGift(Graphics::getGraphics().getTexture(INSTRUCTIONS), sf::Vector2f(500, 300), sf::Vector2f(30, 30)));
}
//------------------------------------------
void Board::draw(int x,int y)
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
	//for (int i = 0; i < m_giftsVec.size(); i++)
	//	m_giftsVec[i]->draw(m_window);
}
//------------------------------------------------
bool Board::checkIfPassedAlready(int y,int x)
{
	if (m_matrix[y][x] == 2)return true;
	if (m_matrix[y][x] == 0) m_matrix[y][x] = 2;
	return false;
}
//-------------------------------------------------
void Board::moveEnemies()
{
	for (int i = 0; i < m_enemiesVec.size(); i++)
		m_enemiesVec[i]->move(*this);

}
//-------------------------------------------------
void Board::handleSpaceBlockage(int x,int y,int& dx,int& dy)
{
	if (m_matrix[x][y] == 1)
	{
		dx = dy = 0;
		for (int i = 0; i < m_enemiesVec.size(); i++)
			floodFill(m_enemiesVec[i]->getIndex());

		for (int i = 0; i < 45; i++)
			for (int j = 0; j < 45; j++)
				if (m_matrix[i][j] == -1) m_matrix[i][j] = 0;
				else m_matrix[i][j] = 1;
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
bool Board::checkIfMatCellEqualTo(sf::Vector2i v,enum TileState state)
{
	return (m_matrix[v.x][v.y] == state);
}
//------------------------------------------------------------
void Board::movePlayer(int& x, int& y, int& dx, int& dy)
{
	m_player.moveP( x, y, dx, dy);
}
//------------------------------------------------------------
void Board::setDirection(sf::Keyboard::Key key, int& dx, int& dy)
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
