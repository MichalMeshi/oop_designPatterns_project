#include "Board.h"
#include "CollisionHandling.h"
#include "Level.h"
//-----------------------------------------------
Board::Board(sf::RenderWindow& window, int curentLevel, int& percent)
	:m_window(window), m_player(std::make_unique<Player>(Graphics::getGraphics().getTexture(PLAYER), sf::Vector2f(40, 40))),
	m_backgroundGame(Graphics::getGraphics().getTexture(SEA), {}, { WIDTH_WINDOW, HIGTH_WINDOW }), m_percentage(percent),
	m_crumbPic(Graphics::getGraphics().getTexture(CRUMB_ANIMATION), {}, { 500,100 }), m_crumbAnimation(m_crumbPic, 500, 100)
{
	clockForGifts.restart();
	createBoard();
}
//פונקציה שיוצרת את הלוח של המשחק
//-----------------------------------------------
void Board::createBoard()
{
	m_matrix.resize(MATRIX_SIZE);
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			m_matrix[i].emplace_back(EMPTY);
			if (i == ZERO || j == ZERO || i == MATRIX_SIZE - 1 || j == MATRIX_SIZE - 1)
				m_matrix[i][j] = BLOCKED;
		}
}
//פונקציה האחראית להדפסת הלוח
//-----------------------------------------------
void Board::draw(std::vector<int> infoVec)
{
	m_backgroundGame.draw(m_window);
	drawTiles(infoVec);
	m_player->draw(m_window);
	drawEnemies();
	drawGifts();
}
//הדפסת אריחים
//------------------------------------------------
void Board::drawTiles(std::vector<int> infoVec)
{
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
}
//הדפסת אויבים
//------------------------------------------------
void Board::drawEnemies()
{
	for (int i = 0; i < m_ballsVec.size(); i++)
		m_ballsVec[i]->draw(m_window);
	for (int i = 0; i < m_spidersVec.size(); i++)
		m_spidersVec[i]->draw(m_window);
	for (int i = 0; i < m_territoryEaterVec.size(); i++)
		m_territoryEaterVec[i]->draw(m_window);
}
//הדפסת מתנות
//------------------------------------------------
void Board::drawGifts()
{
	for (int i = 0; i < m_giftsVec.size(); i++)
		m_giftsVec[i]->draw(m_window);
}
//פוקנציה הבודקת האם השחקן חזר למקום שכבר היה בו
//------------------------------------------------
bool Board::checkIfPassedAlready()
{
	if (m_matrix[m_player->getPlayerYpos()][m_player->getPlayerXpos()] == MIDDLE)
	{
		updateFailure(true);
		return true;
	}
	if (m_matrix[m_player->getPlayerYpos()][m_player->getPlayerXpos()] == EMPTY)
		m_matrix[m_player->getPlayerYpos()][m_player->getPlayerXpos()] = MIDDLE;
	return false;
}
//פונקציה האחראית על תזוזת האויבים
//-------------------------------------------------
bool Board::moveEnemies()
{
	bool isColideWithMiddle = false;
	for (auto& enemy : m_ballsVec)
	{
		enemy->move(*this);
		if ((typeid(*m_player) == typeid(Player)) && m_matrix[enemy->getIndex().x][enemy->getIndex().y] == MIDDLE)
		{
			updateFailure(true);
			isColideWithMiddle = true;
		}
	}
	for (auto& enemy : m_spidersVec)
	{
		enemy->move(*this);
		if ((typeid(*m_player) == typeid(Player)) && m_matrix[enemy->getIndex().x][enemy->getIndex().y] == MIDDLE)
		{
			updateFailure(true);
			isColideWithMiddle = true;
		}
	}
	for (auto& territoryEater : m_territoryEaterVec)
	{
		territoryEater->move(*this);
		if (m_matrix[territoryEater->getIndex().x][territoryEater->getIndex().y] == MIDDLE)
		{
			updateFailure(true);
			isColideWithMiddle = true;
		}
	}
	return isColideWithMiddle;
}
//פוקנציה האחראית על כבישת האריחים
//-------------------------------------------------
void Board::handleSpaceBlockage()
{
	if (m_matrix[m_player->getPlayerYpos()][m_player->getPlayerXpos()] == BLOCKED)
	{
		m_player->setPlayerDx(ZERO);
		m_player->setPlayerDy(ZERO);
		if (m_ballsVec.size() == 0)
			m_matrix[0][0] = EMPTY;
		floodFill();
		
		handleConditionTile();
		updateFailure(false);
	}
}
//פונקציה האחראית על מצב האריחים
//----------------------------------------------------------
void Board::handleConditionTile()
{
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
}
//הפונקציה שאחראית לאלגוריתם החכם של כבישת השטח
//----------------------------------------------------------
void Board::floodFill(sf::Vector2i v)
{
	if (v.x >= ZERO && v.x <= MATRIX_SIZE - 1 && v.y >= ZERO && v.y <= MATRIX_SIZE - 1 && m_matrix[v.x][v.y] == EMPTY) m_matrix[v.x][v.y] = AROUND_ENEMY;
	if (((v.x - 1) >= 0) && v.y >= 0 && v.y <= 44 && m_matrix[v.x - 1][v.y] == EMPTY) floodFill(sf::Vector2i(v.x - 1, v.y));
	if (((v.x + 1) <= 44) && v.y >= 0 && v.y <= 44 && m_matrix[v.x + 1][v.y] == EMPTY) floodFill(sf::Vector2i(v.x + 1, v.y));
	if (((v.y - 1) >= 0) && v.x >= 0 && v.x <= 44 && m_matrix[v.x][v.y - 1] == EMPTY) floodFill(sf::Vector2i(v.x, v.y - 1));
	if (((v.y + 1) <= 44) && v.x >= 0 && v.x <= 44 && m_matrix[v.x][v.y + 1] == EMPTY) floodFill(sf::Vector2i(v.x, v.y + 1));
}
//הזזת השחקן
//------------------------------------------------------------
void Board::movePlayer()
{
	m_player->moveP();
}
//פונקציה האחראית על כיוון התזוזה 
//------------------------------------------------------------
void Board::setDirection(sf::Keyboard::Key key)
{
	switch (key){
	case sf::Keyboard::Key::Right:{
		m_player->setPlayerDx(1); m_player->setPlayerDy(0);
		break;
	}
	case sf::Keyboard::Key::Left:{
		m_player->setPlayerDx(-1); m_player->setPlayerDy(0);
		break;
	}
	case sf::Keyboard::Key::Down:{
		m_player->setPlayerDx(0); m_player->setPlayerDy(1);
		break;
	}
	case sf::Keyboard::Key::Up:{
		m_player->setPlayerDx(0); m_player->setPlayerDy(-1);
		break;
	}
	default:
		return;
	}
}
//פוקנציה האחראית על יצירת המתנות בלוח
//--------------------------------------------
void Board::handleCreateGifts(int& gift_num, int rand_time, Level* l)
{
	if (clockForGifts.getElapsedTime().asSeconds() >= rand_time && gift_num != 0)
	{
		m_giftsVec.emplace_back(GiftFactory::createGift(l));
		gift_num--;
		clockForGifts.restart();
	}
	rotateGifts();
}
//פונקציה המוצאת את הכיוון שאליו האויבים צריכים לזוז לפי מיקום השחקן
//--------------------------------------------
sf::Vector2f Board::findDirectionToMove(int x, int y)
{
	sf::Vector2f pos = { ZERO,ZERO };
	if (m_player->isRight(x))
		pos.x = TO_RIGHT;
	else if (m_player->isLeft(x))
		pos.x = TO_LEFT;
	else if (m_player->isUp(y))
		pos.y = TO_UP;
	else if (m_player->isDown(y))
		pos.y = TO_DOWN;
	if (m_player->isUp(y) && m_player->isRight(x))
	{
		pos.x = TO_RIGHT;
		pos.y = ZERO;
	}
	return pos;
}
//הפונקציה של אכילת השטחים של האויב-אוכל שטחים
//--------------------------------------------------------
void Board::eatCellInMatrix(int i, int j)
{
	if ((!(i <= ZERO || i >= MATRIX_SIZE - 1 || j <= ZERO || j >= MATRIX_SIZE - 1))
		&& (m_matrix[i][j] == BLOCKED || m_matrix[i][j] == MIDDLE)) {
		if (--m_blockCounter <= ZERO)
		{
			m_percentage--;
			m_blockCounter = AMOUNT_FOR_ONE_PERCENT;
		}
		m_matrix[i][j] = EMPTY;
		handleAnimationCrumb(i, j);
	}
}
//פונקציה האחראית על ההתנגשויות של האוביקטים
//---------------------------------------------------------
void Board::handleCollision()
{
	for (int i = 0; i < m_ballsVec.size(); i++)
		if (colide(*m_ballsVec[i], *m_player))
			processCollision(*m_ballsVec[i], *m_player);
	for (int i = 0; i < m_spidersVec.size(); i++)
		if (colide(*m_spidersVec[i], *m_player))
			processCollision(*m_spidersVec[i], *m_player);
	for (int i = 0; i < m_giftsVec.size(); i++)
		if (colide(*m_giftsVec[i], *m_player))
		{
			processCollision(*m_giftsVec[i], *m_player);
			Graphics::getGraphics().getSoundVec()[GIFT_SOUND]->play();
		}
	eraseDeletedObjects();

}
//פונקציה הבודקת האם היתה התנגשות
//-------------------------------------------------------------
bool Board::colide(Object& obj1, Object& obj2)const
{
	sf::FloatRect res;
	auto player = sf::FloatRect(obj2.getDisplay().getSprite().getGlobalBounds());
	return (player.intersects(obj1.getDisplay().getSprite().getGlobalBounds(), res));
}
//פונקציה האחראית ליצירת האויבים בלוח
//-------------------------------------------------------------
void Board::createEnemiesInBoard(int curentLevel, Level* l, std::vector<int> vec)
{
	m_ballsVec = EnemyFactory::createBalls(curentLevel, l);
	m_spidersVec = EnemyFactory::createSpiders(curentLevel, l, vec);
}
//פונקציה האחראית ליצירת אוכל השטחים בלוח
//-------------------------------------------------------------
void Board::createTerritoryEnemiesInBoard(int curentLevel, Level* l, std::vector<int> vec)
{
	m_territoryEaterVec = EnemyFactory::createTerritoryEaters(curentLevel, l, vec);
}
//פונקציה המקפיאה את האויבים שבלוח
//-------------------------------------------------------------
void Board::freezeEnemies()
{
	for (auto& enemy : m_ballsVec)
		enemy->freeze();
	for (auto& enemy : m_spidersVec)
		enemy->freeze();
	for (auto& enemy : m_territoryEaterVec)
		enemy->freeze();
}
//פונקציה המבטלת את הקפאת האויבים
//-------------------------------------------------------------
void Board::unFreezeEnemies()
{
	for (auto& enemy : m_ballsVec)
		enemy->unFreeze();
	for (auto& enemy : m_spidersVec)
		enemy->unFreeze();
	for (auto& enemy : m_territoryEaterVec)
		enemy->unFreeze();
}
//פוקנציה האחראית לתזוזת המתנות על הלוח
//-------------------------------------------------------------
void Board::rotateGifts()
{
	for (int i = 0; i < m_giftsVec.size(); i++)
		m_giftsVec[i]->handleAnimation();
}
//פונקציה האחראית על אנימצית ההתפוררות של אכילת השטח
//-------------------------------------------------------------
void Board::handleAnimationCrumb(int i, int j)
{
	sf::Vector2f pos;
	pos.x = 20 * j + 350 - 15;
	pos.y = 20 * i + 50 - 15;
	m_crumbPic.setPosition(pos);
	m_crumbAnimation.handleAnimation();
	m_crumbPic.draw(m_window);
	m_window.display();
}
//פונקציה שמעדכנת איזה שחקן משחק 
//-------------------------------------------------------------
void Board::setPlayer()
{
	if (typeid(*m_player) != typeid(Player))
		setBackPlayer();
}
//פונקציה שבודקת האם האריח חסום
//-------------------------------------------------------------
bool Board::checkIfBlocked(sf::Vector2i pos)const
{
	return (m_matrix[pos.x][pos.y] == BLOCKED);
}
//פונקציה שבודקת האם האריח לא חסום
//-------------------------------------------------------------
bool Board::checkIUnfBlocked(sf::Vector2i pos)const
{
	return (m_matrix[pos.x][pos.y] == EMPTY || m_matrix[pos.x][pos.y] == MIDDLE);
}
//פונקציה שמחזירה את המיקום של השחקן להתחלה
//-------------------------------------------------------------
void Board::setPlayerPositionToBegining()
{
	m_player->setPlayerPosition(sf::Vector2f(22, 0));
}
//החלפה לשחקן חסין
//-------------------------------------------------------------
void Board::immuneThePlayer()
{
	m_player = std::make_unique < ImmunePlayer>(m_player->getPlayerXpos(), m_player->getPlayerYpos(), m_player->getPlayerDx(), m_player->getPlayerDy());
}
//החלפה לשחקן הורג
//-------------------------------------------------------------
void Board::changePlayerToKilling()
{
	m_player = std::make_unique < KillingPlayer>(m_player->getPlayerXpos(), m_player->getPlayerYpos(), m_player->getPlayerDx(), m_player->getPlayerDy());
}
//החזרה לשחקן הרגיל
//-------------------------------------------------------------
void Board::setBackPlayer()
{
	m_player = std::make_unique<Player>(m_player->getPlayerXpos(), m_player->getPlayerYpos(), m_player->getPlayerDx(), m_player->getPlayerDy());
}
//פונקציה המוחקת את האוביקטים שהשחקן נפגש בהם וצריכים להיפגש
//-------------------------------------------------------------
void Board::eraseDeletedObjects()
{
	std::erase_if(m_ballsVec, [](const auto& ball) { return ball->isDead(); });
	std::erase_if(m_spidersVec, [](const auto& spider) { return spider->isDead(); });
	std::erase_if(m_giftsVec, [](const auto& gift) { return gift->isDead(); });
}
//פונקציה האחראית על צביעת השטח שנכבש ע"י השחקן
//-------------------------------------------------------------
void Board::floodFill()
{
	floodFillOnEnemy(m_ballsVec);
	floodFillOnEnemy(m_territoryEaterVec);
}
//פונקציה האחראית על הפעלת אלגוריתם הפלוד_פיל על האויבים
//-------------------------------------------------------------
template <typename enemyVec>
void Board::floodFillOnEnemy(std::vector<typename enemyVec>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		floodFill(vec[i]->getIndex());
}