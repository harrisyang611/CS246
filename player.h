#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "board.h"
#include "info.h"
#include "IOhandler.h"
#include "subject.h"
#include "tinfo.h"
#include "tstate.h"
#include "pinfo.h"
#include "card.h"
#include "DInfo.h"

extern bool TEST = false;
extern bool Graphics = false;


class Player: public Subject, public TSubject {
	TInfo tInfo;
    DInfo dInfo;

	std::vector<PInfo> p (2);
	int active = 0;
	int inactive = 1;

	PInfo *winner=nullptr;
	bool gameOver=false;

	TextDisplay *td;
	GraphicsDisplay *gd;

	void gameStart();

protected:
	void pSwitch();
	bool checkDead(PInfo *atkr,PInfo *dfdr);
	void checkMDead(PInfo *atkr,int aindx,PInfo *dfdr,int dindx);

public:
	Player(PInfo p1,PInfo p2);
	~Player()=default;
	TInfo getTInfo();
    DInfo getDInfo();

	void modifyMagic(PInfo &p,int ch);
	std::vector<Card> getAllMinion(&p);
	int getMagic();
	void initPlay(int i);

	friend Board;
}

#endif
