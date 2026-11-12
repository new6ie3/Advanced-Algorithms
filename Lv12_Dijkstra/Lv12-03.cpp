#include <iostream>
#include <algorithm>

struct Node
{
	char ch;
	Node* next;
};

class List
{
public:
	List() : head(nullptr), tail(nullptr) {};

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

	void AddNode(char ch)
	{
		Node* newNode = new Node();
		newNode->ch = ch;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void PrintList_two()
	{
		Node* node = head;

		while (node != nullptr)
		{
			std::cout << node->ch;

			if (node->next == nullptr)
				break;

			node = node->next->next;
		}
	}

private:
	Node* head;
	Node* tail;
};

int main()
{
	std::string str = "MINCODING";
	std::reverse(str.begin(), str.end());
	List list;
	
	for (const auto& ch : str)
	{
		list.AddNode(ch);
	}

	list.PrintList_two();

	return 0;
}