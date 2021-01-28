#include "tokenizer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;


void tokenizer::scan(string file) {

	inputFile.open(file);
	if (inputFile.is_open()) {
		while (inputFile.get(curr)) {
			testChar();
			scanString();
		}
		token* newToken = new token();
		newToken->type = "EOF";
		newToken->value = "";
		newToken->line = line;
		tokens.push_back(newToken);
		//print();
		//cout << "Total Tokens = " << tokens.size() << endl;
		//clearMem();
	}
	else {
		cout << "Failed to open file.";
	}
}


void tokenizer::scanString() {
	
	while (isspace(curr)) {
		//if (curr == '\n') {
		//	line++;
		//}
		inputFile.get(curr);
		testChar();
		if (inputFile.eof()) {
			break;
		}
	}

	if (isalpha(curr)) {
		string val = "";
		while (isalnum(curr)) {
			val += curr;
			inputFile.get(curr);
		}
		
		if (val == "Schemes") {
			token* newToken = new token();
			newToken->type = "SCHEMES";
			newToken->value = "Schemes";
			newToken->line = line;
			tokens.push_back(newToken);
		}
		else if (val == "Facts") {
			token* newToken = new token();
			newToken->type = "FACTS";
			newToken->value = "Facts";
			newToken->line = line;
			tokens.push_back(newToken);
		}
		else if (val == "Rules") {
			token* newToken = new token();
			newToken->type = "RULES";
			newToken->value = "Rules";
			newToken->line = line;
			tokens.push_back(newToken);
		}
		else if (val == "Queries") {
			token* newToken = new token();
			newToken->type = "QUERIES";
			newToken->value = "Queries";
			newToken->line = line;
			tokens.push_back(newToken);
		}
		else {
			token* newToken = new token();
			newToken->type = "ID";
			newToken->value = val;
			newToken->line = line;
			tokens.push_back(newToken);
		}
		testChar();
	}
}

void tokenizer::print() {
	ofstream outFile;
	outFile.open("out.txt");
	int size = tokens.size();

	for (int i = 0; i < size; i++) {
		string token;
		token = "(" + tokens.at(i)->type + "," + '"' + tokens.at(i)->value + '"' + "," + to_string(tokens.at(i)->line) + ")";
		cout << token;
		cout << endl;
		outFile << token << endl;
		outFile << "Total Tokens = " << tokens.size() << endl;

	}
}


void tokenizer::checkString() {
	bool endOfString = false;
	string val;
	val += curr;
	int linestart = line;
	while (endOfString == false)
	{
		if (inputFile.peek() == -1)
		{
			token* newToken = new token();
			newToken->type = "UNDEFINED";
			newToken->value = val;
			newToken->line = linestart;
			tokens.push_back(newToken);
			endOfString = true;
		}
		else
		{
			inputFile.get(curr);
			switch (curr)
			{
			case '\n':
			{
				line++;
				val += curr;
				break;
			}
			case '\'':
			{
				val += curr;
				char peek = inputFile.peek();
				if (peek != '\'')
				{
					token* newToken = new token();
					newToken->type = "STRING";
					newToken->value = val;
					newToken->line = linestart;
					tokens.push_back(newToken);
					endOfString = true;
				}
				else
				{
					inputFile.get(curr);
					val += curr;
				}
				break;
			}
			default:
			{
				val += curr;
				break;
			}
			}
		}
	}

}

void tokenizer::findEndOfString() {

}

void tokenizer::testChar() {
	switch (curr) {
	case '(':
	{
		token* newToken = new token();
		newToken->type = "LEFT_PAREN";
		newToken->value = "(";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case ')':
	{
		token* newToken = new token();
		newToken->type = "RIGHT_PAREN";
		newToken->value = ")";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case ',':
	{
		token* newToken = new token();
		newToken->type = "COMMA";
		newToken->value = ",";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case '.':
	{
		token* newToken = new token();
		newToken->type = "PERIOD";
		newToken->value = ".";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case '?':
	{
		token* newToken = new token();
		newToken->type = "Q_MARK";
		newToken->value = "?";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case ':':
	{
		if (inputFile.peek() == '-') {
			inputFile.get();
			token* newToken = new token();
			newToken->type = "COLON_DASH";
			newToken->value = ":-";
			newToken->line = line;
			tokens.push_back(newToken);
			break;
		}
		else {
			token* newToken = new token();
			newToken->type = "COLON";
			newToken->value = ":";
			newToken->line = line;
			tokens.push_back(newToken);
			break;
		}
	}
	case '*':
	{
		token* newToken = new token();
		newToken->type = "MULTIPLY";
		newToken->value = "*";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case '+':
	{
		token* newToken = new token();
		newToken->type = "ADD";
		newToken->value = "+";
		newToken->line = line;
		tokens.push_back(newToken);
		break;
	}
	case '\'':
	{
		checkString();
		break;
	}
	case '#':
	{	
		if (inputFile.peek() != '|') {
			handleComment();
		}
		else if (inputFile.peek() == '|') {
			inputFile.get(curr);
			handleBlock();
		}
		break;
	}
	default:
		if (isalpha(curr)) {
			break;
		}
		if (isspace(curr)) {
			if (curr == '\n' && !inputFile.eof()) {
				line++;
			}
			break;
		}
		if (isdigit(curr)) {
			token* newToken = new token();
			newToken->type = "UNDEFINED";
			newToken->value = curr;
			newToken->line = line;
			tokens.push_back(newToken);
			break;
		}
		if (curr == '\'') {
			break;
		}
		else {
			token* newToken = new token();
			newToken->type = "UNDEFINED";
			newToken->value = curr;
			newToken->line = line;
			tokens.push_back(newToken);
			break;
		}
	}
}

void tokenizer::handleComment() {
	string val;
	val += curr;
	bool endOfComment = false;
	while (!endOfComment) {
		if (curr != '\n' && curr != '\r') {
			if (inputFile.peek() != '\r' && inputFile.peek() != '\n') {
				inputFile.get(curr);
				val += curr;
			}
			else {
				inputFile.get(curr);
				if (curr == '\r' && inputFile.peek() == '\n') {
					inputFile.get(curr);
				}
			}
		}
		else {
			endOfComment = true;
		}
	}
	token* newToken = new token();
	newToken->type = "COMMENT";
	newToken->value = val;
	newToken->line = line;
	tokens.push_back(newToken);
	line++;
}

void tokenizer::handleBlock() {
	string val;
	val += "#|";
	int startline = line;
	bool endOfBlock = false;
	while (!endOfBlock) {
		inputFile.get(curr);
		if (curr == '|' && inputFile.peek() == '#') {
			inputFile.get(curr);
			token* newToken = new token();
			newToken->type = "COMMENT";
			newToken->value = val + "|#";
			newToken->line = startline;
			tokens.push_back(newToken);
			return;
		}
		if (inputFile.eof()) {
			token* newToken = new token();
			newToken->type = "UNDEFINED";
			newToken->value = val;
			newToken->line = startline;
			tokens.push_back(newToken);
			return;
		}
		val += curr;
		if (curr == '\n') {
			line++;
		}
	}
}

void tokenizer::clearMem() {
	for (int i = 0; i < tokens.size(); i++) {
		delete tokens.at(i);
	}
}