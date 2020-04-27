#include <windows.h>
#include <string>

#include "LongNumArrays.h"

using namespace NSLongNumArrays;

int** LongNumArrays::AllocArrays()
{
	this->lNumArrs = (int**)malloc(sizeof(int*) * this->rows);
	int iter = 0;

	for (iter = 0; iter < this->rows; iter += 1)
	{
		if (!(this->lNumArrs[iter] = (int*)malloc(sizeof(int) * this->cols))) {
			printf("Failed some malloc: (%d)\n", GetLastError());
			return NULL;
		}
	}

	return this->lNumArrs;
}

void LongNumArrays::FillArrays(int initNum)
{
	int row = 0;
	int col = 0;

	int ramNum = 0;

	for (col = 0; col < cols; col += 1)
	{
		for (ramNum = (initNum + col) % 2, row = 0; row < this->rows; ramNum = (ramNum + 1) % 2, row += 1)
		{
			this->lNumArrs[row][col] = ramNum;
		}
	}
}

void LongNumArrays::FreeArrays()
{
	int iter = 0;

	for (iter = 0; iter < this->rows; iter += 1)
	{
		free(lNumArrs[iter]);
	}

	free(lNumArrs);
}

std::string LongNumArrays::Greeting() {
	return std::string("Hello world!");
}
