#include "Encrypt.h"
#include <fstream>

std::string Encrypt::plain() const
{
	return _plain;
}
std::string Encrypt::cipher() const
{
	return _cipher;
}
void Encrypt::read(std::string filename, char plain_or_cipher)
{
	std::string& destination = (plain_or_cipher == 'p') ? _plain : _cipher;
	std::ifstream file(filename);
	std::string line;
	destination = "";
	while (std::getline(file, line))
	{
		destination += line + "\n";
	}
	file.close();
}
void Encrypt::write(std::string filename, char plain_or_cipher)
{
	std::string& source = (plain_or_cipher == 'p') ? _plain : _cipher;
	std::ofstream file(filename);
	file << source;
	file.close();
}