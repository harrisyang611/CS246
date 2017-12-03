#ifndef Ability_h
#define Ability_h

class Ability {
    
private:
    const bool summon;
    const bool summon3;
    const bool magic;
    const bool destroy;
    const int ATKchange = 0;
    const int LPchange = 0;
    
public:
    virtual ~Ability(){};
    virtual void useAbility(Player* p);
    virtual void useAbility(Player* p1, Player* p2, Minion* m);
};


#endif /* Ability_h */
