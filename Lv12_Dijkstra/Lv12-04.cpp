#include <iostream>

#define SIZE 100

struct Node
{
	int num;
	Node* next;
};

class List
{
public:
	List() : head(nullptr), tail(nullptr), cnt(0)
	{

	}

	~List()
	{
		Node* node = head;
		while (node != nullptr)
		{
			Node* next = node->next;
			delete node;
			node = next;
		}

		head = nullptr;
		tail = nullptr;
	}

	void AddNode(int num)
	{
		Node* node;
		if (cnt < SIZE)
		{
			node = &pool[cnt];
			cnt++;
		}
		else
		{
			node = new Node;
		}

		node->num = num;
		node->next = nullptr;

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}

	void PrintNodes()
	{
		Node* node = head;
		while (node != nullptr)
		{
			std::cout << node->num << ' ';

			node = node->next;
		}
	}

private:
	Node pool[SIZE];
	Node* head;
	Node* tail;
	int cnt;
};

int main()
{
	List list;
	int arr[] = { 5, 3, 4, 1, 2, 7 };
	for (int i = 0; i < 6; ++i)
	{
		list.AddNode(arr[i]);
	}

	list.PrintNodes();

	return 0;
}