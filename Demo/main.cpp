#include <iostream>
#include "..\Heap\Heap.h"

using namespace dbms;
int main()
{
	Heap heap{ 8, 9, 5, 6, 3, 1 };
	heap.Delete(0);
	return 0;
}