#include "pch.h"
#include "CppUnitTest.h"
#include "..\Heap\Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dbms;

namespace Tests
{
	TEST_CLASS(HeapTests)
	{
	public:
		
		TEST_METHOD(Insert_EmptyHeap_Success)
		{
			// arrange
			Heap heap{};
			int expected = 1;

			// act
			heap.Insert(1);
			int actual = heap.GetMin();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Insert_EmptyHeap_Size)
		{
			// arrange
			Heap heap{};
			const size_t expected = 1;

			// act
			heap.Insert(1);
			const auto actual = heap.GetSize();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Insert_Heap_Size3)
		{
			// arrange
			Heap heap{1, 2};
			const size_t expected = 3;

			// act
			heap.Insert(3);
			const auto actual = heap.GetSize();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ToString_Heap_Success)
		{
			// arrange
			Heap heap{1, 3, 6};
			const std::string expected{"{ 1, 3, 6 }"};

			// act
			const auto actual = heap.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(RandomInsert_Heap_Success)
		{
			// arrange
			Heap heap{ 8, 9, 5, 6, 3, 1 };
			
			const std::string expected{ "{ 1, 5, 3, 9, 6, 8 }" };

			// act
			const auto actual = heap.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetMin_ValidHeap_Success)
		{
			// arrange
			Heap heap{ 8, 9, 6, 5, 3, 1 };
			auto expected = 1;

			// act
			auto actual = heap.GetMin();

			//
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(DeleteParent_ValidIndex_Success)
		{
			// arrange
			Heap heap{ 8, 9, 5, 6, 3, 1 };
			const std::string expected{ "{ 1, 6, 3, 9, 8 }" };

			// act
			heap.Delete(1);

			// assert
			Assert::AreEqual(expected, heap.ToString());
		}

		TEST_METHOD(DeleteRoot_ValidIndex_Success)
		{
			// arrange
			Heap heap{ 8, 9, 5, 6, 3, 1 };
			const std::string expected{ "{ 3, 5, 8, 9, 6 }" };

			// act
			heap.Delete(0);

			// assert
			Assert::AreEqual(expected, heap.ToString());
		}
	};
}
