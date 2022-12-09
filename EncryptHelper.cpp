#include "EncryptHelper.h"
bool isMixAlphabet(std::string str) {
	uint32_t check = 0x03ffffff;
	if (str.length() != 26) return false;
	for (char c : str) {
		if (c < 'a' || c > 'z') {
			return false;
		}
		else {
			check &= ~(1 << (c - 'a'));
		}
	}
	return check == 0;
}