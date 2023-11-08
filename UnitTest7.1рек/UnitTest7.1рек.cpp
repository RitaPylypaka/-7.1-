#include "pch.h"
#include "CppUnitTest.h"
#include "../пр7.1рек/7.1рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71рек
{
	TEST_CLASS(UnitTest71рек)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int colCount = 2;
			int rowCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 6;
			a[1][1] = 4;
			a[0][1] = 12;
			a[1][0] = 5;
			int S = 0;
			int k = 0;
			Calc(a, rowCount, colCount, S, k,0,0);
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
			Assert::AreEqual(S, 12);

		}
	};
}
