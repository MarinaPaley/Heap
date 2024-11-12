#include <sstream>
#include "Heap.h"

void dbms::Heap::Expand()
{
	Heap temp(this->capacity * expand_factor);
	std::copy(this->heap, this->heap + this->size, temp.heap);
	this->Swap(temp);
}

void dbms::Heap::Swap(Heap& other)
{
	std::swap(this->capacity, other.capacity);
	std::swap(this->size, other.size);
	std::swap(this->heap, other.heap);
}

dbms::Heap::Heap()
	: size{ 0 },
	  capacity{ default_capacity }, 
	  heap{new int[this->capacity]}
{
}

dbms::Heap::Heap(const int capacity)
{
	if (capacity <= 0)
	{
		throw std::out_of_range("Емкость кучи должна быть больше нуля!");
	}

	this->size = 0;
	this->capacity = static_cast<size_t>(capacity);
	this->heap = new int[this->capacity];
}

dbms::Heap::~Heap()
{
	delete[] this->heap;
}

dbms::Heap::Heap(const Heap& other) : 
	size{ other.size },
	capacity{ other.capacity },
	heap{ new int[this->capacity] }
{
	std::copy(other.heap, other.heap + other.size, this->heap);
}

dbms::Heap::Heap(Heap&& other) noexcept
	: Heap()
{
	this->Swap(other);
}

dbms::Heap& dbms::Heap::operator=(const Heap& other)
{
	if (this == &other)
	{
		return *this;
	}

	Heap temp(other);
	this->Swap(temp);
	return *this;
}

dbms::Heap& dbms::Heap::operator=(Heap&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	this->Swap(other);
	return *this;
}

std::string dbms::Heap::ToString() const
{
	std::stringstream buffer{};
	buffer << "{ ";
	size_t i = 0;
	for ( ;i < this->size - 1; ++i)
	{
		buffer << this->heap[i] << ", ";
	}
	buffer << this->heap[i] << " }";

	return buffer.str();
}

std::ostream& dbms::operator<<(std::ostream& out, const Heap& heap)
{
	return out << heap.ToString();
}

bool dbms::operator==(const Heap& lha, const Heap& rha)
{
	return lha.ToString() == rha.ToString();
}

std::wstring dbms::ToString(const Heap& heap)
{
	const auto temp = heap.ToString();
	return std::wstring{ temp.cbegin(), temp.cend() };
}
