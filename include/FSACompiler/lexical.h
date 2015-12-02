#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <simple_tokenizer/simple_tokenizer.h>

#define EXPECTED_TOKEN 0
#define EXPECTED_PARAM 1

class Lexical {
	public:
	Lexical(std::string file_name);
	~Lexical();
	
	bool analize();
	bool isValidSymbol(std::string symbol);
	bool isNextOnlyParam(std::string symbol);
	void assert(bool condition, int aerrno, int line, std::string token);

	protected:
	std::string file;
	short state;
	const std::vector<std::string> symbols = {
		"name", "include", "set", "input_parameter", "output_parameter", "input",
		"function", "initial_state", "state", "condition", "from"
	};
	
	const std::vector<std::string> next_only_param = {
		"name", "include", "input_parameter", "output_parameter", "function", 
		"initial_state", "state", "condition", "from"
	};
	
	const std::vector<std::string> errno_string = {
		"Invalid symbol, expected token."
	};
};
