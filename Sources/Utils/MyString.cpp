//
// Created by 10484 on 24-5-8.
//
#pragma execution_character_set("utf-8")
#include "MyString.h"

#include <sstream>


std::vector<std::string> Utils::StringSplit(const std::string& str, char delim) {
	std::stringstream ss(str);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}

