#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include<iostream>
#include<vector>
#include"predicate.h"
#include "token.h"
using namespace std;

class datalogProgram {
	public:
		//methods
		datalogProgram(){}
		~datalogProgram(){}

		void addScheme(predicate* p);
		void addFact();
		void addRule();
		void addQuery();
		void printSchemes();
		void printSchemesParams(int j);


		//parameters
		vector<predicate*> schemes;
		vector<predicate*> facts;
		vector<predicate*> queries;

};



#endif