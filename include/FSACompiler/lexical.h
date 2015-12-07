#pragma once

#include <vector>
#include <simple_tokenizer/simple_tokenizer.h>

#include "FSACompiler/Analizer.h"

class Lexical : Analizer{
	public:
	Lexical();
	~Lexical();
	
	bool analize(std::string line);

	std::string result_symbol;
	std::string result_value;
};
