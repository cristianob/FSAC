#include "FSACompiler/syntactic.h"

Syntactic::Syntactic() :
	result_id(-1)
{}

Syntactic::~Syntactic() {}

bool Syntactic::analize(size_t line_n, std::string key, std::string value) {
	this->assert(this->isValidSymbol(key), 1, this->errno_string[0], line_n, key);
	this->resolveSymbol(key);

	return true;
}

bool Syntactic::isValidSymbol(std::string symbol) {
	return (std::find(this->symbols.begin(), this->symbols.end(), symbol) != this->symbols.end());
}

short int Syntactic::resolveSymbol(std::string symbol) {
	//Transduction Machine
	if(symbol == "name")
		this->result_id = SYMBOL_NAME;
	else if(symbol == "include")
		this->result_id = SYMBOL_INCLUDE;
	else if(symbol == "input_parameter")
		this->result_id = SYMBOL_INPUT_PARAMETER;
	else if(symbol == "output_parameter")
		this->result_id = SYMBOL_OUTPUT_PARAMETER;
	else if(symbol == "input")
		this->result_id = SYMBOL_INPUT;
	else if(symbol == "initial_state")
		this->result_id = SYMBOL_INITIAL_STATE;
	else if(symbol == "state")
		this->result_id = SYMBOL_STATE;
	else if(symbol == "condition")
		this->result_id = SYMBOL_CONDITION;
	else if(symbol == "from")
		this->result_id = SYMBOL_FROM;
}
