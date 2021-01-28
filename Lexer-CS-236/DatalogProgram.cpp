#include "DatalogProgram.h"
#include<iostream>
#include<string>
#include<vector>
#include"parameter.h"


void datalogProgram::addScheme(predicate* p) {
	this->schemes.push_back(p);
}

void datalogProgram::printSchemes() {
	cout << "Schemes(" << to_string(schemes.size()) << "):" << endl;
	for (int i = 0; i < schemes.size(); i++) {
		cout << "  " << schemes.at(i)->name << "(" << schemes.at(i)->headParameter;
		printSchemesParams(i);
		cout << ")" << endl;
	}
}

void datalogProgram::printSchemesParams(int j) {
	for (int i = 0; i < schemes.at(j)->parameters.size(); i++) {
			cout << "," << schemes.at(j)->parameters.at(i)->name;
		}
}



void datalogProgram::addFact() {

}
void datalogProgram::addRule() {

}
void datalogProgram::addQuery() {

}