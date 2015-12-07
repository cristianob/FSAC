#pragma once

#include <iostream>
#include <string>

class Analizer {
	public:
	Analizer();
	~Analizer();
	
	void assert(bool condition, int aerrno, std::string errno_string, size_t line, std::string token);
};
