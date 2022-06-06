#include "TerritoryEater.h"
#include "Board.h"
void TerritoryEater::move(Board& b)
{
	sf::Vector2f pos = m_move->move(b);
	m_display.setPosition(pos);
	////m_display.rotate();
	b.eatCellInMatrix( ((pos.y - 50) / 20), ((pos.x - 350) / 20));

	//if (!(int((int(pos.y) - 50) / 20) == 0 ))
	//	b.eatCellInMatrix(((pos.x - 350) / 20), ((pos.y - 50) / 20));

	//if (!(int((int(pos.x) - 350) / 20) == 0))
	//	b.eatCellInMatrix(((pos.x - 350) / 20), ((pos.y - 50) / 20));

	//if(!(int((int(pos.y) - 50) / 20) == 44))
	//	b.eatCellInMatrix(((pos.x - 350) / 20), ((pos.y - 50) / 20));

	//if (!(int((int(pos.x) - 350) / 20) == 44))
	//	b.eatCellInMatrix(((pos.x - 350) / 20), ((pos.y - 50) / 20));

	//else
	//{
	//	m_display.rotate();

	//}
	
}
