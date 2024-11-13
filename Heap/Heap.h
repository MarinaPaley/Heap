#pragma once
#include <string>
#include <ostream>
namespace dbms
{
	class Heap;
	std::ostream& operator<<(std::ostream& out, const Heap& heap);
	bool operator==(const Heap& lha, const Heap& rha);
	std::wstring ToString(const Heap& heap);

	/**
	* @brief  Класс куча.
	*/
	class Heap final
	{
	private:
		const static size_t default_capacity = 2;
		const static size_t expand_factor = 2;
		size_t size;
		size_t capacity;
		int* heap;
		void Expand();
		void Swap(Heap& other);
		void MinHeapify(size_t i);
		void DecreaseKey(size_t i, int value);
		void Validate(size_t i);
		void CheckIndex(size_t i) const;
		size_t Parent(size_t i) const;
		size_t Left(size_t i) const;
		size_t Right(size_t i) const;
	public:
		Heap();
		Heap(const int capacity);
		~Heap();
		Heap(const Heap& other);
		Heap(Heap&& other) noexcept;
		Heap& operator=(const Heap& other);
		Heap& operator=(Heap&& other) noexcept;

		void Insert(const int key);
		void Delete(const size_t i);
		int GetMin() const;
		void ExtractMin();
		bool IsEmpty() const;
		std::string ToString() const;
		size_t GetSize() const;
	};
}
