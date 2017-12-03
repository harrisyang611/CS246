#ifndef ritual_h
#define ritual_h

#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include "ability.h"
#include "cards.h"
using namespace std;

class Ritual: public Card {
    
protected:
    string name;
    string description;
    int Cost;
    const Ability* ability;
    int ablCost;
    int charges;
    
public:
    Ritual(string s);
    ~Ritual(){delete ability};
    
    Bool canUseAbl();
    void update();
    void modify(int ablCostCh, int chargeCh);
    string getType() {return "Ritual"; };
    
};


#endif /* ritual_h */
