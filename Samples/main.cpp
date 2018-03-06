#include <iostream>

#include "BinarizationRunner.h"

int main(int argc, char *argv[])
{
	std::cout << "Running samples..." << std::endl;
	
	BinarizationRunner::runOpenCVTreshold();
	BinarizationRunner::runDumbTreshold();

	std::cout << "Press any key..." << std::endl;
	char ch;
	std::cin >> ch;
	return 0;
}
