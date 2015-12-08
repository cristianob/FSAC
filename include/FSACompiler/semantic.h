#pragma once

#include <string>
#include <vector>

#include "FSACompiler/Analizer.h"
#include "FSACompiler/syntactic.h"

class Semantic : Analizer{
	public:
	Semantic();
	~Semantic();
	
	bool analize(size_t line_n, short symbol_id, std::string symbol_value);

	private:
};
