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
	* @brief  ласс куча.
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
	public:
		Heap();
		Heap(const int capacity);
		~Heap();
		Heap(const Heap& other);
		Heap(Heap&& other) noexcept;
		Heap& operator=(const Heap& other);
		Heap& operator=(Heap&& other) noexcept;

		void Insert(const int key);
		void Delete(const int key);
		int GetMin() const;
		void ExtractMin();
		std::string ToString() const;
	}
}
