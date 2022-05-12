#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.1D/Pair.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT33B
{
	TEST_CLASS(UT33B)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Pair t(1, 1), f(1, 1);

			Assert::AreEqual(t.GetHrn(), f.GetHrn());
		}
	};
}