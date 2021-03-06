#ifndef minion_h
#define minion_h

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "ability.h"
#include "cards.h"
#include "CardInfo.h"

class Minion: public Card {
    
protected:
    std::string name;
    std::string description;
    int cost;
    int ATK;
    int LP;
    
    std::vector<std::string> EnSeq;
    int actionCount = 1;
    int actionCountStable = 1;
    
    bool silence;
    Ability* ability = nullptr;
    int abilityCost;
    
    CardInfo Card;
    
public:
    Minion(std::string s);
    ~Minion() {delete ability};
    
    // check if the player has enough magic to let the minion use the ability
    bool canUseAbl(Player &p);
    void update();                  // update user's magic after using ability
    void modify(int ATKch, int LPch);   // modify minion's ATK/LP
    void destroy();                 // set LP to 0
    bool acting();                  // check actionCount > 0
    void modifyAct(int);            // modify action count
    void modifyACS(int);            // modify action cound stable
    void setAct() {actionCount = actionCountStable; } ;                 // reset action count
    
    // accessors
    std::string getType() {return "Minion"; };
    int getACS() { return actionCountS; };   // get action count stable

    void disenchant();
    void disenchantA();
    
    void updateCardInfo();
};

#endif /* minion_h */
