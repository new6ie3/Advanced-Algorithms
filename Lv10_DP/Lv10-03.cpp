#include <iostream>
#include <vector>

struct Node
{
	int num;
	Node* next;
};

Node* head = nullptr;
Node buffer[100];
int cnt = 0;

void AddNode(int num)
{
	Node* node = nullptr;

	if (cnt < 100)
	{
		buffer[cnt].num = num;
		buffer[cnt].next = nullptr;
		node = &buffer[cnt];
		cnt++;
	}
	else
	{
		node = new Node;
		node->num = num;
		node->next = nullptr;
	}

	if (head == nullptr)
		head = node;
	else
	{
		for (Node* n = head; n != nullptr; n = n->next)
		{
			if (n->next == nullptr)
			{
				n->next = node;
				break;
			}
		}
	}

}

void PrintNode()
{
	for (Node* n = head; n != nullptr; n = n->next)
	{
		std::cout << n->num << ' ';
	}
}

int main()
{
	std::vector<int> vec = { 5, 3, 4, 1, 2, 7 };
	for (int n : vec)
	{
		AddNode(n);
	}

	PrintNode();


	return 0;
}