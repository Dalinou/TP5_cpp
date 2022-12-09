#include <iostream>
#include "Enigma.h"

int main() {
	
	std::string default_key = "abcdefghijklmnopqrstuvwxyz";
	std::string key = "aqwzsxedcrfvtgbyhnpmolikuj";
	Enigma clear(default_key);
	Enigma cipher(key);
	
	clear.read("plain.txt", 'p');
	clear.encode();
	clear.write("cipher_default.txt", 'c');
	std::cout << clear.plain() << std::endl << clear.cipher() << std::endl;
	clear.setOffset(0);
	clear.read("cipher_default.txt", 'c');
	clear.decode();
	clear.write("plain_default.txt", 'p');
	std::cout << clear.plain() << std::endl << clear.cipher() << std::endl;
	
	cipher.read("plain.txt", 'p');
	cipher.encode();
	cipher.write("cipher_cipher.txt", 'c');
	std::cout << cipher.plain() << std::endl << cipher.cipher() << std::endl;
	cipher.setOffset(0);
	cipher.read("cipher_cipher.txt", 'c');
	cipher.decode();
	cipher.write("plain_cipher.txt", 'p');
	std::cout << cipher.plain() << std::endl << cipher.cipher() << std::endl;

	return 0;
}