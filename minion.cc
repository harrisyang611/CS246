#include "minion.h"
#include "card.h"
using namespace std;

Minion::Minion(string s){
    
    
};

bool Minion::canUseAbl(Player &p){
    if (silence) return false;
    if (abilityCost > p.getMagic()) return false;
    return true;
};

void Minion::modify(int ATKch, int LPch){
    ATK += ATKch;
    LP += LPch;
};

void Minion::destroy(){
    LP = 0;
};

bool Minion::acting(){
    if (actionCount > 0) {
        return true;
    } else return false;
};

void Minion::modifyAct(int i) {
    actionCount += i;
};

void Minion::modifyACS(int i) {
    actionCountStable += i;
};

void disenchant(){
    string cur = *EnSeq.back();
    Enseq.pop_back();

    char info = cur[0];
    if (info == '*'){
        ATK /= cur[1]-'0';
        LP /= cur[1];-'0';
    }
    else if (info == '+'){
        ATK -= cur[1]-'0';
        LP -= cur[1]-'0';
    }
    else if (info == 't'){
        actionCount -= cur[1]-'0';
    }
    else if (info == 'c'){
        abilityCost -= cur[1]-'0';
    }
    else if (info == 's'){
        for (auto p:EnSeq){
            if (p[0] == info) return;
        }
        silence = false;
    }
}

void disenchantA(){
    while (EnSeq.size()!=0){
        disenchant();
    }
}