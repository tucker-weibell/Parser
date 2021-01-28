#ifndef TOKEN_H
#define TOKEN_H
#include<string>
using namespace std;

class token {			// Token Class - Creates token instances

public:
	// Variables
	string type;		// Contains the token type
	string value;		// Contains the token value
	int line;			// Containts the line the token is on

	// Functions
	token();			// Initializes token

};



#endif // !TOKEN
