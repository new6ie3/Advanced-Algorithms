#include <iostream>

struct Node
{
	char code;
	int killCount;
	Node* next;
};

Node bucket[100];


int main()
{
	bucket['A'] = { 'A', 5, nullptr };
	bucket['B'] = {'B', 10, nullptr};
	bucket['D'] = {'D', 22, nullptr};
	bucket['Z'] = {'Z', 16, nullptr};

	Node* cur = nullptr;
	for (int i = 0; i < 100; ++i)
	{

		if (bucket[i].code)
		{
			if (cur != nullptr)
				cur->next = &bucket[i];

			cur = &bucket[i];
		}

	}

	std::cout << bucket['B'].killCount;

	return 0;
}