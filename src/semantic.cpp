#include "FSACompiler/semantic.h"

Semantic::Semantic() {
	this->prop_include = std::vector<std::string>();
	this->prop_input   = std::vector<std::string>();
	this->prop_state   = std::vector<State>();
	this->last_state   = NULL;
}

Semantic::~Semantic() {}

bool Semantic::analize(size_t line_n, short symbol_id, std::string symbol_value) {
	std::vector<std::string> tmp;
	Semantic::State s;
	
	switch(symbol_id) {
	case SYMBOL_NAME:
		this->prop_name = symbol_value;
		break;
	case SYMBOL_INCLUDE:
		this->prop_include.push_back(symbol_value);
		break;
	case SYMBOL_INPUT_PARAMETER:
		this->prop_input_parameter = symbol_value;
		break;
	case SYMBOL_OUTPUT_PARAMETER:
		this->prop_output_parameter = symbol_value;
		break;
	case SYMBOL_INPUT:
		this->prop_input.push_back(symbol_value);
		break;
	case SYMBOL_INITIAL_STATE:
		this->prop_initial_state = symbol_value;
		break;
	case SYMBOL_CONDITION:
		this->last_state->condition.push_back(symbol_value);
		break;
	case SYMBOL_FROM:
		tmp = std::vector<std::string>();
		split_and_trim(symbol_value, ',', tmp);
		this->last_state->from.push_back(tmp);
		break;
	case SYMBOL_STATE:
		s = State();
		s.name = symbol_value;
		this->prop_state.push_back(s);
		this->last_state = &this->prop_state.back();
		break;
	}
	
	return this->validate();
}

bool Semantic::validate() {
	//TODO: Validateeeeee
	return true;
}
