#include "Utility/Encrypter.h"


kl::Encrypter::Encrypter() {
	generateNewKeys();
}

void kl::Encrypter::generateNewKeys() {
	for (auto& key : keys) {
		uint keySize = 0;
		do {
			keySize = rand() % 7 + 2;
		}
		while ([&]() {
			for (auto& k : keys) {
				if (k.size() == keySize) {
					return true;
				}
			}
			return false;
		}());
		key.resize(keySize);
		for (auto& k : key) {
			k = rand() % 256;
		}
	}
}

void kl::Encrypter::encrypt(void* data, uint64 dataSize) const {
	for (auto& key : keys) {
		for (uint64 i = 0; i < dataSize; i++) {
			((byte*) data)[i] ^= key[i % key.size()];
		}
	}
}

void kl::Encrypter::decrypt(void* data, uint64 dataSize) const {
	encrypt(data, dataSize);
}

std::ostream& kl::operator<<(std::ostream& os, const Encrypter& encrypter) {
	for (uint i = 0; i < 5; i++) {
		os << "keys[" << i << "] = { ";
		for (uint k = 0; k < encrypter.keys[i].size() - 1; k++) {
			os << uint(encrypter.keys[i][k]) << ", ";
		}
		os << uint(encrypter.keys[i].back()) << " }" << std::endl;
	}
	return os;
}