#include <stdlib.h>

namespace NSLongNumArrays {
	class __declspec(dllexport) LongNumArrays {
	public:
		int** lNumArrs;
		int rows;
		int cols;

		int** AllocArrays();
		void FillArrays(int initNum);
		void FreeArrays();

		std::string Greeting();

		LongNumArrays(int rows, int cols)
		{
			this->lNumArrs = NULL;
			this->rows = rows;
			this->cols = cols;
		}
	};
}