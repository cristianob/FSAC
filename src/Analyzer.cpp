#include "FSACompiler/Analyzer.h"

Analyzer::Analyzer(){}
Analyzer::~Analyzer(){}

void Analyzer::assert(bool condition, int aerrno, std::string errno_string, size_t line, std::string token) {
	if(!condition) {
		std::cerr << "Error " << aerrno << ": " << errno_string 
		<< " In token: " << token << ", line " << line << std::endl;
		
		exit(errno);
	}
}
