#pragma once
#include "Encrypt.h"
#include <string>
#include <array>
class Enigma2 : public Encrypt
{
public:
	Enigma2(std::array<std::string, 2> keys, std::array<int, 2> offsets = { 0,0 });
	void encode() override;
	void decode() override;
	void setOffsets(std::array<int, 2> offsets);
	std::array<int, 2> getOffsets();
private:
	std::array<std::string,2> _keys;
	std::array<std::string,2> _reverse_keys;
	std::array<int,2> _offsets;
	
};

