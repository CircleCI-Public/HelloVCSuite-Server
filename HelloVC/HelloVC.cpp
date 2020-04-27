#include <iostream>

#include "LongNumArrays.h"

#define DEFAULT_SIZE_MB 1024

#define MINIMUM_MEMORY_MB 1
#define ARRAY_LENGTH MINIMUM_MEMORY_MB * 1024 * 1024 / 4

#define __USE_MINGW_ANSI_STDIO 1

void runLongNumArraySeq(int rows, int cols) {
	NSLongNumArrays::LongNumArrays lNumArrs(rows, cols);

	lNumArrs.AllocArrays();
	lNumArrs.FillArrays(0);
	lNumArrs.FillArrays(1);
	lNumArrs.FreeArrays();

	lNumArrs.AllocArrays();
	lNumArrs.FillArrays(1);
	lNumArrs.FillArrays(0);
	lNumArrs.FreeArrays();

	std::cout << lNumArrs.Greeting();
}

int HelloVC(int argc, char* argv[])
{
	int rows = argc > 1 ? atoi(argv[1]) : DEFAULT_SIZE_MB;
	int cols = ARRAY_LENGTH;

	if (rows < 1)
	{
		std::cout << "Invalid size specified.\n";
		return 1;
	}

	runLongNumArraySeq(rows, cols);

	return 0;
}
