#ifndef __BOARD_H__
#define __BOARD_H__

#include "player.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

class Board{
	Player plyr;

public:
	Board(Player plyr);
	void gameStart();

};

#endif