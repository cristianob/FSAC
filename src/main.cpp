#include "FSACompiler/lexical.h"
#include "FSACompiler/syntactic.h"
#include "FSACompiler/algorithm.h"

#include <iostream>

int main() {
	std::ifstream fs;
	std::string line;
	int line_n = 1;
	
	fs.open("exemplo.fsa");
	
	Lexical   lexical_analizer   = Lexical();
	Syntactic syntactic_analizer = Syntactic();
	while(std::getline(fs, line)) {
		line = trim(line);
		if(line == "")
			continue;
			
		lexical_analizer.analize(line);
		syntactic_analizer.analize(line_n, lexical_analizer.result_symbol, lexical_analizer.result_value);
		std::cout << lexical_analizer.result_symbol << " - " << lexical_analizer.result_value << std::endl;
		
		line_n++;
	}
	
	fs.close();
	
	return 0;
}
