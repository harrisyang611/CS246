#ifndef __SPELLS_H__
#define __SPELLS_H__

#include "cards.h"

class Spells:public Cards{
	bool banish;
	bool unsummon;
	bool recharge;
	bool disenchant;
	bool necromacy;
	bool blizzard;
public:
	void useSpell(PInfo &player,int indx=0){
		vector<std::shared_ptr<Cards>> oBoard = (player.getBoard()).getStack();

		if (banish){

			oBoard.begin()+(indx-1)=nullptr;
		}
		else if (unsummon){
			vector<std::shared_ptr<Cards>> oHand = (player.getHand()).getStack();
			if (oHand.size()<5){
				oHand.emplace_back(oBoard[indx-1]);
				oBoard.begin()+(indx-1)=nullptr;
			}
		}
		else if (recharge){
		vector<std::shared_ptr<Cards>> oRit = (player.getRit()).getStack();
		oRit->accessCharge()+=3;
		}
		else if (disenchant){
			oBoard[indx-1]->revert();
		}
		else if (necromacy){
			vector<std::shared_ptr<Cards>> oGYard = (player.getGYard()).getStack();
			std::shared_ptr<Cards>>topC = oGYard[0];
			oGYard.pop_front();
			

		}
	}
}

#endif