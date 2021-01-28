#include<iostream>
#include<string>
#include "token.h"

token::token() {
	this->type = "";
	this->value = "";
	this->line = 0;
}