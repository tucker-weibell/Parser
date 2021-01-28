#ifndef TOKENIZER_H
#define	TOKENIZER_H
#include "token.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class tokenizer {

public:
	void scan(string file);
	void scanString();
	void checkString();
	void findEndOfString();
	void handleComment();
	void handleBlock();
	void testChar();
	void print();
	void clearMem();
	char curr;
	int line = 1;
	ifstream inputFile;
	vector<token*> tokens;
};


#endif // !TOKENIZER_H

