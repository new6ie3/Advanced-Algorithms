#include <iostream>

struct Node
{
	char ch;
	Node* next;
};

Node buffer[100];
int cnt = 0;
Node* head = nullptr;

Node* myAlloc(int ch, Node* next)
{
	buffer[cnt].ch = ch;
	buffer[cnt].next = next;
	return &buffer[cnt++];
}

void AddNode(char ch, Node* next)
{
    Node* node = nullptr;

    if (cnt < 100)
    {
        node = myAlloc(ch, next);
    }
    else
    {
        node = new Node;
        node->ch = ch;
        node->next = next;
    }

    if (head == nullptr)
    {
        head = node;
    }
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
		std::cout << n->ch << ' ';
	}
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		AddNode(i + 'A', nullptr);
	}

	PrintNode();

	return 0;
}