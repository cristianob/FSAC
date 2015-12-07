#include "FSACompiler/syntactic.h"

Syntactic::Syntactic() {}

Syntactic::~Syntactic() {}

bool Syntactic::analize(size_t line_n, std::string key, std::string value) {
	this->assert(this->isValidSymbol(key), 1, this->errno_string[0], line_n, key);

	return true;
}

bool Syntactic::isValidSymbol(std::string symbol) {
	return (std::find(this->symbols.begin(), this->symbols.end(), symbol) != this->symbols.end());
}
