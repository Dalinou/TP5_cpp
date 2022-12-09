#include "Enigma.h"
#include "EncryptHelper.h"

Enigma::Enigma(std::string key, int offset) :
	_offset(offset%26) {
	if (isMixAlphabet(key)) {
		_key = key;
		_reverse_key = "";
		for (char c = 'a'; c <= 'z'; ++c) {
			_reverse_key += (char)('a' + _key.find(c));
		}
	}
	else
		throw std::string("Key must be a mix of the alphabet");
}
void Enigma::encode() {
	_cipher = _plain;
	for (char& c : _cipher) {
		if (c >= 'a' && c <= 'z') {
			c = _key.at((c - 'a' + _offset) % 26);
			++_offset %= 26;
		}
		else if (c >= 'A' && c <= 'Z') {
			c = _key.at((c - 'A' + _offset) % 26) - 'a' + 'A';
			++_offset %= 26;
		}
	}
}
void Enigma::decode() {
	_plain = _cipher;
	for (char& c : _plain) {
		if (c >= 'a' && c <= 'z') {
			c = ((_reverse_key.at(c - 'a') - _offset - 'z') % 26) + 'z';
			++_offset %= 26;
		}
		else if (c >= 'A' && c <= 'Z') {
			c = ((_reverse_key.at(c - 'A') - _offset - 'z') % 26) + 'Z';
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