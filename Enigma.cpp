#include "Enigma.h"
#include <iostream>

Enigma::Enigma(std::string key, int offset) :
	_offset(offset%26) {
	if (isMixAlphabet(key)) {
		_key = key;
		_reverse_key = "";
		for (char c = 'a'; c <= 'z'; ++c) {
			_reverse_key += (char)('a' + _key.find(c));
		}
		std::cout << "Key:\t\t" << _key << std::endl;
		std::cout << "Reverse key:\t" << _reverse_key << std::endl;
		for (int i = 0; i < 26; ++i) {
			std::cout << (char)('a' + i) << " -> " << _key[i] << " -> " << _reverse_key[_key[i]-'a'] << std::endl;
		}
	}
	else
		throw std::string("Key must be a mix of the alphabet");
}
void Enigma::encode() {
	_cipher = _plain;
	for (char& c : _cipher) {
		if (c >= 'a' && c <= 'z') {
			c = _key[(c - 'a' + _offset) % 26];
			++_offset %= 26;
		}
		else if (c >= 'A' && c <= 'Z') {
			c = _key[(c - 'A' + _offset) % 26] - 'a' + 'A';
			++_offset %= 26;
		}
	}
}
void Enigma::decode() {
	_plain = _cipher;
	for (char& c : _plain) {
		if (c >= 'a' && c <= 'z') {
			c = ((_reverse_key[c - 'a'] - _offset - 'z') % 26) + 'z';
			++_offset %= 26;
		}
		else if (c >= 'A' && c <= 'Z') {
			c = ((_reverse_key[c - 'A'] - _offset - 'z') % 26) + 'Z';
			++_offset %= 26;
		}
	}
}

void Enigma::setOffset(int offset) {
	_offset = offset%26;
}
int Enigma::getOffset() {
	return _offset;
}

bool Enigma::isMixAlphabet(std::string str) {
	uint32_t check = 67108863;
	if (str.length() > 26) {
		return false;
	}
	for (char c : str) {
		if (c < 'a' || c > 'z') {
			return false;
		}
		else {
			check &= ~(1 << (c - 'a'));
		}
	}
	if (check == 0) {
		return true;
	}
	else {
		return false;
	}
}