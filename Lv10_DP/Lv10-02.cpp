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
	List()
	{
		head = nullptr;
		cnt = 0;
	}

	void AddNode(char ch)
	{
		Node* node = new Node;
		node->ch = ch;
		node->next = nullptr;

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

		cnt++;
	}

	void PrintNode()
	{
		for (Node* n = head; n != nullptr; n = n->next->next)
		{
			std::cout << n->ch << ' ';
		}
	}

private:
	Node* head;
	int cnt;
};

int main()
{
	List list;
	std::string str = "CODING";
	std::reverse(str.begin(), str.end());

	for (char c : str)
	{
		list.AddNode(c);
	}

	list.PrintNode();


	return 0;
}