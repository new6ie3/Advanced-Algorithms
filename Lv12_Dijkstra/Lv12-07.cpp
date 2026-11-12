#include <iostream>
#include <vector>

std::vector<std::pair<char, int>> vec = 
{
	{'A', 21}, {'E', 15}, {'E', 6}, {'A', 15}, {'E', 34}, {'B', 32}, {'C', 35},
	{'C', 36}, {'D', 14}, {'A', 3},
};

constexpr int size = 100;

struct Node
{
	char group;
	int id;
	Node* next;
};

class Groups
{
public:
	Groups() : head(nullptr), tail(nullptr), cnt(0) {};
	~Groups()
	{
		Node* node = head;

		while (node != nullptr)
		{
			Node* next = node->next;

			if (node < buf || node >= buf + size)
				delete node;

			node = next;
		}
	}

	void AddNode(char group, int id)
	{
		Node* node = AllacNode(group, id);

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

	void PrintGroupID(char group)
	{
		Node* node = head;
		while (node != nullptr)
		{
			if (node->group == group)
				std::cout << node->id << ' ';

			node = node->next;
		}
	}

private:
	Node* AllacNode(char group, int id)
	{
		Node* node;
		if (cnt < size) 
			node = &buf[cnt++];
		else node = new Node();

		node->id = id;
		node->group = group;
		node->next = nullptr;

		return node;
	}

	Node buf[size];
	Node* head;
	Node* tail;
	int cnt;
};

int main()
{
	Groups groups;
	for (const auto&[group, id] : vec)
	{
		groups.AddNode(group, id);
	}

	groups.PrintGroupID('A');

	return 0;
}