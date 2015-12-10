#pragma once

#include <string>
#include <vector>

#include "FSACompiler/algorithm.h"
#include "FSACompiler/Analyzer.h"
#include "FSACompiler/syntactic.h"

class Semantic : Analyzer{
	public:
	Semantic();
	~Semantic();
	
	bool analize(size_t line_n, short symbol_id, std::string symbol_value);
	
	struct State {
		public:
		std::string name;
		std::vector<std::string> condition;
		std::vector<std::vector<std::string>> from;
	};

	std::string			prop_name;
	std::vector<std::string>	prop_include;
	std::string			prop_input_parameter;
	std::string			prop_output_parameter;
	std::vector<std::string>	prop_input;
	std::string			prop_initial_state;
	std::vector<State>		prop_state;
	
	private:
	State *last_state;
	bool validate();
};
