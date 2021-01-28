#ifndef PARSER_H
#define PARSER_H

#include"token.h"
#include<iostream>
#include<string>
#include<vector>
#include "DatalogProgram.h"
#include "parameter.h"

class parser {
	public:
		//methods
		void parse();
		void match(string type);
		void parseScheme();
		void parseSchemeList();
		vector<parameter*> parseIdList();
		vector<parameter*> params;
		vector<token*> tokenList;
		datalogProgram program;


};

#endif