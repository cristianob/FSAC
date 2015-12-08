#include "FSACompiler/semantic.h"

Semantic::Semantic() {}

Semantic::~Semantic() {}

bool Semantic::analize(size_t line_n, short symbol_id, std::string symbol_value) {
	std::cout << symbol_id << " - " << symbol_value << std::endl;

	return true;
}
