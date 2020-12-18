#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4(рекурс)/Lab_12.4(рекурс).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab124рекурс
{
	TEST_CLASS(UnitTestLab124рекурс)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* L = NULL;
			Spusok* L1 = NULL;
			Spusok* L2 = NULL;
			Spusok* T, * G;

			int x = 0, inf, N = 2, i = 0;
			T = L;
			inf = -7;
			Creata(L, T, inf, N, i);

			T = L;
			Process(L, L1, L2, T, G, i);			

			T = L2;
			int l = T->inf;
			Assert::AreEqual(l, -7);
		}
	};
}
