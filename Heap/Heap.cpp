#include <sstream>
#include "Heap.h"

void dbms::Heap::Expand()
{
	Heap temp(static_cast<size_t>(this->capacity * expand_factor));
	std::copy(this->heap, this->heap + this->size, temp.heap);
	temp.size = this->size;
	this->Swap(temp);
}

void dbms::Heap::Swap(Heap& other)
{
	std::swap(this->capacity, other.capacity);
	std::swap(this->size, other.size);
	std::swap(this->heap, other.heap);
}

void dbms::Heap::MinHeapify(size_t i)
{
	auto left = this->Left(i);
	auto right = this->Right(i);
	auto smallest = i;
	if (left < this->size && this->heap[left] < this->heap[i])
		smallest = left;
	if (right < this->size && this->heap[right] < this->heap[smallest])
		smallest = right;

	if (smallest != i)
	{
		std::swap(this->heap[i], this->heap[smallest]);
		MinHeapify(smallest);
	}
}

void dbms::Heap::DecreaseKey(size_t i, int value)
{
	this->CheckIndex(i);

	this->heap[i] = value;

	this->Validate(i);
}

void dbms::Heap::Validate(size_t i)
{
	while (i != 0 && this->heap[this->Parent(i)] > this->heap[i])
	{
		std::swap(this->heap[i], this->heap[this->Parent(i)]);
		i = this->Parent(i);
	}
}

void dbms::Heap::CheckIndex(size_t i) const
{
	if (i >= this->size)
	{
		throw std::out_of_range("Неправильный индекс!");
	}
}

size_t dbms::Heap::Parent(size_t i) const
{
	return (i - 1) / 2; 
}

size_t dbms::Heap::Left(size_t i) const
{
	return (2 * i + 1);;
}

size_t dbms::Heap::Right(size_t i) const
{
	return (2 * i + 2);;
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
		throw std::out_of_range("Ёмкость кучи должна быть больше нуля!");
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

void dbms::Heap::Insert(const int key)
{
	if (this->size == this->capacity)
	{
		this->Expand();
	}
	auto i = this->size;
	this->heap[this->size++] = key;
	this->Validate(i);
}

void dbms::Heap::Delete(const size_t i)
{
	this->CheckIndex(i);

	auto value = this->heap[0] - 1;
	this->DecreaseKey(i, value);
	this->ExtractMin();
}

int dbms::Heap::GetMin() const
{
	return this->heap[0];
}

void dbms::Heap::ExtractMin()
{
	if (this->IsEmpty())
	{
		throw std::out_of_range("Куча пустая");
	}

	this->heap[0] = this->heap[--this->size];

	MinHeapify(0);
}

bool dbms::Heap::IsEmpty() const
{
	return this->size == 0;
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

size_t dbms::Heap::GetSize() const
{
	return this->size;
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
