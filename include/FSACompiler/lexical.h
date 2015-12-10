#pragma once

#include <vector>
#include <simple_tokenizer/simple_tokenizer.h>

#include "FSACompiler/Analyzer.h"

class Lexical : Analyzer{
	public:
	Lexical();
	~Lexical();
	
	bool analize(std::string line);

	std::string result_symbol;
	std::string result_value;
};
