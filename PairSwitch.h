#pragma once
#include <string>
#include <vector>
#include "EncryptHelper.h"
template<int _pair_number> // -1 for reflector, 10 for plugboard
class PairSwitch
{
public:
	PairSwitch(std::string key);
	PairSwitch(std::vector<std::string> pair_list);
	void pass_through(char& c) const;
private:
	std::string _key;
	void _check_pair_number();
};

