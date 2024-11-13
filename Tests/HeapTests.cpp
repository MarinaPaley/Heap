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
			Heap heap{};
			heap.Insert(1);
			heap.Insert(2);
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
			Heap heap{};
			heap.Insert(1);
			heap.Insert(3);
			heap.Insert(6);
			const std::string expected{"{ 1, 3, 6 }"};

			// act
			const auto actual = heap.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(RandomInsert_Heap_Success)
		{
			// arrange
			Heap heap{};
			heap.Insert(8);
			heap.Insert(1);
			heap.Insert(6);
			heap.Insert(5);
			heap.Insert(3);
			heap.Insert(9);
			
			const std::string expected{ "{ 1, 3, 6, 5, 9, 8 }" };

			// act
			const auto actual = heap.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}
	};
}
