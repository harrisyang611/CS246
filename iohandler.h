#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <vector>
#include <iostream>
#include <memory>
#include <stringstream>
#include "pinfo.h"
#include "enchantment.h"
#include "minion.h"
#include "ritual.h"
#include "spell.h"


struct Holder{
	std::string input;
	std::vector<char> pos;
};

class IOHandler{
public:
	static std::unique_ptr<Holder> stdio(std::istream in);
	static std::string fileRead(std::string name);
	static std::vector<Card *> makeDeck(std::string name="default.deck");
};

#endif