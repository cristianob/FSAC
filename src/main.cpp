#include <iostream>
#include <clocale>
#include <cstdlib>
#include <unistd.h>

#include "FSACompiler/algorithm.h"
#include "FSACompiler/lexical.h"
#include "FSACompiler/syntactic.h"
#include "FSACompiler/semantic.h"
#include "FSACompiler/output.h"

void print_version();
void print_help();
void print_no_file();
void print_file_not_found(char* file_name);
void parse_file(char* file_name);

char *prg_name;

int main(int argc, char **argv) {
	setlocale(LC_CTYPE, "");
	
	prg_name = argv[0];
	
	// Parsing command-line options
	short int c;
	while ( (c = getopt(argc, argv, "vh")) != -1) {
		switch(c) {
		case 'v': 
			print_version();
			break;
		case 'h':
		default:
			print_help();
			break;
		}
	}
	
	// Checking input_file argument
	if(argc < optind+1) {
		print_no_file();
	}
	else if(argc > optind+1) {
		std::cerr << "[Error] Too many arguments." << std::endl;
		print_help();
	}
	
	parse_file(argv[optind]);
	
	return 0;
}

void parse_file(char* file_name) {
	std::ifstream fs;
	std::string line;
	int line_n = 1;
	
	fs.open(file_name, std::ifstream::in);
	if ((fs.rdstate() & std::ifstream::failbit) != 0)
		print_file_not_found(file_name);
	
	Lexical   lexical_analizer   = Lexical();
	Syntactic syntactic_analizer = Syntactic();
	Semantic  semantic_analizer  = Semantic();
	while(std::getline(fs, line)) {
		line = trim(line);
		if(line == "")
			continue;
			
		lexical_analizer.analize(line);
		syntactic_analizer.analize(line_n, lexical_analizer.result_symbol, lexical_analizer.result_value);
		semantic_analizer.analize(line_n, syntactic_analizer.result_id, lexical_analizer.result_value);
		
		line_n++;
	}	
	fs.close();
	
	Output output = Output(&semantic_analizer, std::string(file_name));
	output.generate_files();
}

void print_version() {
	std::cerr << "V.0.1alpha" << std::endl;
	exit(-1);
}

void print_help() {
	std::cerr << "Finite State Automata Compiler - V.0.1alpha" << std::endl
		  << "Author: Cristiano Costa"	<< std::endl
		  << std::endl
		  << "Usage: " << prg_name << " [-hv] [input_file]" << std::endl
		  << "\t-h - Prints this help" << std::endl
		  << "\t-v - Prints program version" << std::endl;
	exit(-1);
}

void print_no_file() {
	std::cerr << "[Error] No input_file specified." << std::endl
		  << "Usage: " << prg_name << " [-hv] [input_file]" << std::endl;
	exit(-1);
}

void print_file_not_found(char* file_name) {
	std::cerr << "[Error] File \"" << file_name << "\" not found." << std::endl
		  << "Usage: " << prg_name << " [-hv] [input_file]" << std::endl;
	exit(-1);
}
