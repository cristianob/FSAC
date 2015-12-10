#pragma once

#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>

/*
 * Trimming algorithm, thanks to David G
 * http://stackoverflow.com/a/17976541
 */
inline std::string trim(const std::string &s) {
	auto wsfront=std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
	return std::string(wsfront,std::find_if_not(s.rbegin(),std::string::const_reverse_iterator(wsfront),[](int c){return std::isspace(c);}).base());
}

/*
 * Split algorithm, thanks to Evan Teran, modified to trim after the split
 * http://stackoverflow.com/a/236803
 */
inline std::vector<std::string> &split_and_trim(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(trim(item));
	}
	
	return elems;
}

inline std::string strtoupper(std::string str) {
	int leng = str.length();
	for(int i=0; i < leng; i++)
		if (97 <= str[i] && str[i] <= 122)
			str[i] -= 32;
			
	return str;
}

inline std::string strtolower(std::string str) {
	int leng = str.length();
	for(int i=0; i < leng; i++)
		if (65 <= str[i] && str[i] <= 90)
			str[i] += 32;
	
	return str;
}
