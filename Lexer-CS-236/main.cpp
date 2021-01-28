#include "token.h"
#include "tokenizer.h"
#include "Parser.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	/*main.cpp - your main file should contain only the main function. No global variables.
	Your main function should be smalland serve the following purposes : verify commandline arguments, instantiate instance of the Lexer class, and pass the input to Lexer
	and let it run.For this project, your main will then need to get the Tokens from the
	Lexerand print them out in a specified format(so the pass - off driver can check it
	for correctness).At the end,*/

	tokenizer tokenizer;
	tokenizer.scan(argv[1]);
	parser parser;
	parser.tokenList = tokenizer.tokens;
	parser.parse();


	return 0;

}