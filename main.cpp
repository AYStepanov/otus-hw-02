#include "lib.h"

#include <iostream>

int main(int, char **) {
	std::cout << "Version: "
		      << version()
		      << '\n'
	          << "Hello, world!"
		      << std::endl;
	return 0;
}
