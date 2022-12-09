#pragma once
#include <string>
#include "Encrypt.h"
class Enigma : public Encrypt
{
public:
	Enigma(std::string key, int offset = 0);
	void encode() override;
	void decode() override;
	void setOffset(int offset);
	int getOffset();
private:
	std::string _key;
	std::string _reverse_key;
	int _offset;
	
};

