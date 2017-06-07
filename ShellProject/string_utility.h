#pragma once

#include <string>
#include <vector>

class StringUtility
{
public:
	static std::vector<std::string> Split(std::string& stringValue, std::string& delimiter);
	static void Split(std::string& stringValue, std::string& delimiter, std::vector<std::string>& splitedStringVector);

private:
	StringUtility();
};

