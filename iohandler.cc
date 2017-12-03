#include "iohandler.h"
#include <fsream>
using namespace std;

unique_ptr<Holder> IOHandler::stdio(istream in){
	make_unique<Holder> hldr;
	string cmd;
	in>>cmd;
	hldr->info=cmd;

	char pos;
	while (in>>pos){
		(hldr->pos).emplace_back(pos);
	}
	in.clear();
	return hldr;
}

string IOHandler::fileRead(string name){
	ifstream file;
	file.open(name+".card");
	string line;
	string fileInfo = "";
	while (getline(file,line)){
		fileInfo += line;
		fileInfo += '\n';
		line.clear();
	}
	return string{fileInfo};
}

vector<Card *> IOHandler::makeDeck(string name){
	ifstream file;
	file.open(name);

	string line;
	ifsream cFile;
	string cLine;

	vector<Card *> v;
	while (getline(file,line)){
		cFile.open(line+".card");
		getline(cFile,cLine);
		if (cLine == "Enchantment"){
			v.emplace_back(new Enchantment(line));
		}
		else if (cLine == "Minion"){
			v.emplace_back(new Minion(line));
		}
		else if (cLine == "Ritual"){
			v.emplace_back(new Ritual(line));
		}
		else if (cLine == "Spell"){
			v.emplace_back(new Spell(line));
		}
		cFile.close();
	}
}