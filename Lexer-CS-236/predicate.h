#ifndef PREDICATE_H
#define PREDICATE_H
#include "parameter.h"
#include<string>
#include<vector>
using namespace std;

class predicate {
	public:
		string name;
		string headParameter;
		vector<parameter*> parameters;

		void addParam(vector<parameter*> params);
};

#endif
