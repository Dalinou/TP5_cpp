#include "Enigma2.h"
#include "EncryptHelper.h"

Enigma2::Enigma2(std::array<std::string, 2> keys, std::array<int, 2> offsets) :
	_offsets(offsets) {
	for (auto offset : offsets) offset %= 26;
	for (int i = 0; i < 2;i++) {
		if (isMixAlphabet(keys.at(i))) {
			_keys.at(i) = keys.at(i);
			_reverse_keys.at(i) = "";
			for (char c = 'a'; c <= 'z'; ++c) {
				_reverse_keys.at(i) += (char)('a' + _keys.at(i).find(c));
			}
		}
		else
			throw std::string("Key must be a mix of the alphabet");
	}
}

void Enigma2::encode() {
	_cipher = _plain;
	for (char& c : _cipher) {
		if (c >= 'a' && c <= 'z') {
			c = _keys.at(0).at((c - 'a' + _offsets.at(0)) % 26);
			c = _keys.at(1).at((c - 'a' + _offsets.at(1)) % 26);
			++_offsets.at(0) %= 26;
			if (_offsets.at(0) == 0) {
				++_offsets.at(1) %= 26;
			}
		}
		else if (c >= 'A' && c <= 'Z') {
			c = _keys.at(0).at((c - 'A' + _offsets.at(0)) % 26);
			c = _keys.at(1).at((c - 'a' + _offsets.at(1)) % 26) - 'a' + 'A';
			++_offsets.at(0) %= 26;
			if (_offsets.at(0) == 0) {
				++_offsets.at(1) %= 26;
			}
		}
	}
}

void Enigma2::decode() {
	_plain = _cipher;
	for (char& c : _plain) {
		if (c >= 'a' && c <= 'z') {
			c = ((_reverse_keys.at(1).at(c - 'a') - _offsets.at(1) - 'z') % 26) + 'z';
			c = ((_reverse_keys.at(0).at(c - 'a') - _offsets.at(0) - 'z') % 26) + 'z';
			++_offsets.at(0) %= 26;
			if (_offsets.at(0) == 0) {
				++_offsets.at(1) %= 26;
			}
		}
		else if (c >= 'A' && c <= 'Z') {
			c = ((_reverse_keys.at(1).at(c - 'A') - _offsets.at(1) - 'z') % 26) + 'z';
			c = ((_reverse_keys.at(0).at(c - 'a') - _offsets.at(0) - 'z') % 26) + 'Z';
			++_offsets.at(0) %= 26;
			if (_offsets.at(0) == 0) {
				++_offsets.at(1) %= 26;
			}
		}
	}
}

void Enigma2::setOffsets(std::array<int,2> offsets) {
	_offsets.at(0) = offsets.at(0) % 26;
	_offsets.at(1) = offsets.at(1) % 26;
}
std::array<int, 2> Enigma2::getOffsets() {
	return _offsets;
}