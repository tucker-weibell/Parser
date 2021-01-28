#include "Parser.h"
#include "predicate.h"
#include "DatalogProgram.h"
#include<string>

void parser::parse() {

	//SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

	try {
		match("SCHEMES");
		match("COLON");
		parseScheme();
		parseSchemeList();
	}
	catch (token* error) {
		cout << "Failure!" << endl;
		cout << "(" + error->type + "," + error->value + "," + to_string(error->line) + ")" << endl;
	}
}
void parser::match(string type) {
	
	if (tokenList.at(0)->type == type) {
		tokenList.erase(tokenList.begin());
	}
	else {
		throw tokenList.at(0);
	}
}

void parser::parseScheme() {

	//ID LEFT_PAREN ID idList RIGHT_PAREN

	predicate* scheme = new predicate();
	scheme->name = tokenList.at(0)->value;

	match("ID");
	match("LEFT_PAREN");
	scheme->headParameter = tokenList.at(0)->value;
	match("ID");
	scheme->addParam(parseIdList());
	match("RIGHT_PAREN");
	program.addScheme(scheme);
	program.printSchemes();
}

void parser::parseSchemeList() {

}

vector<parameter*> parser::parseIdList() {

	//COMMA ID IdList

	if (tokenList.at(0)->type != "RIGHT_PAREN") {
		match("COMMA");
		parameter* newParam = new parameter();
		newParam->name = tokenList.at(0)->value;
		params.push_back(newParam);
		match("ID");
		params = parseIdList();
	}
	return params;

}