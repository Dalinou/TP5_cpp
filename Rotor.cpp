#include "Rotor.h"
#include "EncryptHelper.h"
Rotor::Rotor(std::string key, uint offset, std::vector<uint> notches) :
	_offset(offset % 26) {
	if (isMixAlphabet(key)) {
		_key = key;
		_reverse_key = "";
		for (char c = 'a'; c <= 'z'; ++c) 
			_reverse_key += (char)('a' + _key.find(c));
		}
	else
		throw std::string("Key must be a mix of the alphabet");
	for (auto notch : notches)
		_notches.push_back(notch % 26);
}
bool Rotor::rotate() {
	++_offset %= 26;
	for (auto notch : _notches)
		if (notch == _offset)
			return true;
	return false;
}
void Rotor::setOffset(uint offset) {
	_offset = offset % 26;
}
void Rotor::forward(char& c) const {
	if (isMinuscule(c)) {
		c = _key.at((c - 'a' + _offset) % 26);
	}
	else if (isMajuscule(c)) {
		c = _key.at((c - 'A' + _offset) % 26) - 'a' + 'A';
	}
}
void Rotor::backward(char& c) const {
	if (isMinuscule(c)) {
		c = ((_reverse_key.at(c - 'a') - _offset - 'z') % 26) + 'z';
	}
	else if (isMajuscule(c)) {
		c = ((_reverse_key.at(c - 'A') - _offset - 'z') % 26) + 'Z';
	}
}