#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "FSACompiler/algorithm.h"
#include "FSACompiler/semantic.h"

class Output {
	public:
	Output(Semantic *sa, std::string file_name);
	~Output();
	
	bool generate_files();
	bool output_header();
	
	private:
	Semantic *semantic_analyzer;	
	std::string file_name;
	std::string file_name_normalized;
	
	void normalize_file_name();
};
