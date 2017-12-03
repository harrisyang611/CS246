#ifndef card_h
#define card_h

#include <string>
#include "Player.h"
#include "PInfo.h"
#include "CardInfo.h"
using namespace std;

class Card {

public:
    virtual ~Card();
    
    // return the card type (Minion, Enchantment, Spell, or Ritual)
    virtual String getType();
    
    
    // modify the card's ATK and LP value
    virtual modify(int Ach, int Lch);
    virtual updateCardInfo();
    
    friend Player;
    friend PInfo;
    
}


#endif /* card_h */
