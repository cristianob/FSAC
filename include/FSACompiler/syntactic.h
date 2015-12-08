#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include "FSACompiler/Analizer.h"

#define SYMBOL_NAME		0
#define SYMBOL_INCLUDE		1
#define SYMBOL_INPUT_PARAMETER	2
#define SYMBOL_OUTPUT_PARAMETER	3
#define SYMBOL_INPUT		4
#define SYMBOL_INITIAL_STATE	5
#define SYMBOL_STATE		6
#define SYMBOL_CONDITION	7
#define SYMBOL_FROM		8

class Syntactic : Analizer {
	public:
	Syntactic();
	~Syntactic();
	
	bool analize(size_t line_n, std::string key, std::string value);
	short int resolveSymbol(std::string symbol);
	bool isValidSymbol(std::string symbol);
	
	short int result_id;

	private:
	const std::vector<std::string> symbols = {
		"name", "include", "set", "input_parameter", "output_parameter", "input",
		"initial_state", "state", "condition", "from"
	};

	const std::vector<std::string> errno_string = {
		"Invalid symbol, expected a key-value."
	};
};
