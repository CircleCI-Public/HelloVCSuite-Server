#include "CppUnitTest.h"

#include <windows.h>
#include <string>

#include "../HelloVC/LongNumArrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestNSLongNumArrays
{
	TEST_CLASS(TestLongNumArrays)
	{
	public:
		TEST_METHOD(TestFill)
		{
			NSLongNumArrays::LongNumArrays inst(2, 3);

			inst.AllocArrays();
			inst.FillArrays(0);

			Assert::AreEqual(0, inst.lNumArrs[0][0]);
			Assert::AreEqual(1, inst.lNumArrs[0][1]);
			Assert::AreEqual(0, inst.lNumArrs[0][2]);
			Assert::AreEqual(1, inst.lNumArrs[1][0]);
			Assert::AreEqual(0, inst.lNumArrs[1][1]);
			Assert::AreEqual(1, inst.lNumArrs[1][2]);

			inst.FreeArrays();
			inst.AllocArrays();
			inst.FillArrays(1);

			Assert::AreEqual(1, inst.lNumArrs[0][0]);
			Assert::AreEqual(0, inst.lNumArrs[0][1]);
			Assert::AreEqual(1, inst.lNumArrs[0][2]);
			Assert::AreEqual(0, inst.lNumArrs[1][0]);
			Assert::AreEqual(1, inst.lNumArrs[1][1]);
			Assert::AreEqual(0, inst.lNumArrs[1][2]);
		}
		TEST_METHOD(TestGreeting)
		{
			NSLongNumArrays::LongNumArrays inst(0, 0);

			std::string expect = std::string("Hello world!");
			std::string actual = inst.Greeting();

			Assert::AreEqual(expect, actual);
		}
	};
}
