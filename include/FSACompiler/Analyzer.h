#pragma once

#include <iostream>
#include <string>

class Analyzer {
	public:
	Analyzer();
	~Analyzer();
	
	void assert(bool condition, int aerrno, std::string errno_string, size_t line, std::string token);
};
