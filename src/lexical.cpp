#include "FSACompiler/lexical.h"
#include "FSACompiler/algorithm.h"

Lexical::Lexical() :
	result_symbol(""),
	result_value("")
{}

Lexical::~Lexical() {}

bool Lexical::analize(std::string line) {
	SimpleTokenizer tokenizer(line);
	
	tokenizer.nextToken();
	this->result_symbol = tokenizer.getToken();
	
	tokenizer.nextToken("#");
	this->result_value = trim(tokenizer.getToken());
	
	return true;
}
