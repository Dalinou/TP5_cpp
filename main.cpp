#include <iostream>
#include "Enigma.h"

int main() {
	
	/*std::cout << "Hello World!" << std::endl;
	std::string default_key = "abcdefghijklmnopqrstuvwxyz";
	std::string key = "aqwzsxedcrfvtgbyhnpmolikuj";
	Enigma clear(default_key);
	Enigma cipher(key);
	
	clear.read("plain.txt", 'p');
	clear.encode();
	clear.write("cipher_default.txt", 'c');
	clear.setOffset(0);
	clear.read("cipher_default.txt", 'c');
	clear.decode();
	clear.write("plain_default.txt", 'p');

	cipher.read("plain.txt", 'p');
	cipher.encode();
	cipher.write("cipher_cipher.txt", 'c');
	cipher.setOffset(0);
	cipher.read("cipher_cipher.txt", 'c');
	cipher.decode();
	cipher.write("plain_cipher.txt", 'p');
	*/

	int i = 0, j = 0;
	for (int _ = 0; _ < 100; _++) {
		std::cout << "i :\t" << i << "\t";
		std::cout << (i %= 26)++ << "\t";
		std::cout << i << std::endl;
		std::cout << "j :\t" << j << "\t";
		std::cout << (++j %= 26) << "\t";
		std::cout << j << std::endl;
	}
	return 0;
}