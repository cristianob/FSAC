#include "FSACompiler/lexical.h"

Lexical::Lexical(std::string file_name) :
	file(file_name),
	state(EXPECTED_TOKEN)
{}

Lexical::~Lexical() {}

bool Lexical::analize() {
	std::ifstream fs;
	fs.open(this->file);
	
	std::string line;
	
	int line_n = 1;
	while(std::getline(fs, line)) {		
		SimpleTokenizer tokenizer(line);
		bool end_line = false;
		while(tokenizer.nextToken()) {
			switch(this->state) {
				case EXPECTED_TOKEN:
					assert(this->isValidSymbol(tokenizer.getToken()), 1, line_n, tokenizer.getToken());
					
					if(this->isNextOnlyParam(tokenizer.getToken())) {
						end_line = true;
						break;
					}
					
					break;
				
				case EXPECTED_PARAM:
					break;
			}
			
			if(end_line)
				break;
		}
		
		line_n++;
	}
	
	fs.close();
	
	return true;
}

bool Lexical::isValidSymbol(std::string symbol) {
	return (std::find(this->symbols.begin(), this->symbols.end(), symbol) != this->symbols.end());
}

bool Lexical::isNextOnlyParam(std::string symbol) {
	return (std::find(this->next_only_param.begin(), this->next_only_param.end(), symbol) != this->next_only_param.end());
}

void Lexical::assert(bool condition, int aerrno, int line, std::string token) {
	if(!condition) {
		std::cout << "Error " << aerrno << ": " << this->errno_string[aerrno-1] 
		<< " In token: " << token << ", line " << line << std::endl;
		
		exit(errno);
	}
}
