#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <simple_tokenizer/simple_tokenizer.h>

#include "FSACompiler/Analizer.h"

class Syntactic : Analizer {
	public:
	Syntactic();
	~Syntactic();
	
	bool analize(size_t line_n, std::string key, std::string value);
	bool isValidSymbol(std::string symbol);

	private:
	const std::vector<std::string> symbols = {
		"name", "include", "set", "input_parameter", "output_parameter", "input",
		"initial_state", "state", "condition", "from"
	};

	const std::vector<std::string> errno_string = {
		"Invalid symbol, expected a key-value."
	};
};
