#include <iostream>

struct Node
{
	char ch;
	Node* next;
};

Node buf[100];
int bufCnt = 0;

Node* head = nullptr;
Node* tail = nullptr;

Node* myAlloc(char ch)
{
	Node* newNode = nullptr;

	if (bufCnt < 100)
	{
		newNode = &buf[bufCnt];
		bufCnt++;
	}
	else
		newNode = new Node();

	newNode->ch = ch;
	newNode->next = nullptr;

	return newNode;
}

void AddNode(char ch)
{
	Node* newNode = myAlloc(ch);

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

void PrintNodes()
{
	for (Node* node = head; node != nullptr; node = node->next)
	{
		std::cout << node->ch << ' ';
	}
}

int main()
{
	for (char c = 'A'; c <= 'E'; ++c)
	{
		AddNode(c);
	}

	PrintNodes();

	return 0;
}