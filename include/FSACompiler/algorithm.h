#pragma once

#include <cctype>
#include <string>
#include <algorithm>

/*
 * Trimming algorithm, thanks to David G
 * http://stackoverflow.com/a/17976541
 */
inline std::string trim(const std::string &s) {
	auto wsfront=std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
	return std::string(wsfront,std::find_if_not(s.rbegin(),std::string::const_reverse_iterator(wsfront),[](int c){return std::isspace(c);}).base());
}
