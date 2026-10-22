#include <iostream>
#include <queue>
#include <vector>

void Heap_Sort(std::vector<int>& vec)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
	for (int v : vec)
	{
		heap.push(v);
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		int top = heap.top();
		heap.pop();
		vec[i] = top;
	}

}


int main()
{
	std::vector<int> vec = { 6, 5, 3, 1, 8, 7, 2, 4 };
	Heap_Sort(vec);

	return 0;
}