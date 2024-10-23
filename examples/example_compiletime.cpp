#include <iostream>

#include "../fnv1a32.h"
#include "../fnv1a64.h"

int main(int argc, char* argv[]) {
	std::cout << "C++ Example" << std::endl;

	// run-time
	std::cout << "run-time" << std::endl;
	std::cout << "fnv1a32_str( \"aleks-net\" ) returns " << std::hex << fnv1a32_str("aleks-net") << std::endl;
	std::cout << "fnv1a64_str( \"aleks-net\" ) returns " << std::hex << fnv1a64_str("aleks-net") << std::endl;


	// compile-time
	std::cout << "compile-time" << std::endl;
	std::cout << "fnv1a32_str( \"aleks-net\" ) returns " << std::hex << FNV1A32("aleks-net") << std::endl;
	std::cout << "fnv1a64_str( \"aleks-net\" ) returns " << std::hex << FNV1A64("aleks-net") << std::endl;

	// example compile-time use case
	uint64_t hash = FNV1A64("D");
	switch (hash) {
		case FNV1A64( "A"):
			std::cout << "option A" << std::endl;
			break;

		case FNV1A64("B"):
			std::cout << "option B" << std::endl;
			break;

		case FNV1A64("C"):
			std::cout << "option C" << std::endl;
			break;

		case FNV1A64("D"):
			std::cout << "option D" << std::endl;
			break;

		case FNV1A64("E"):
			std::cout << "option E" << std::endl;
			break;
	}

	return 0;
}