#include <iostream>

constexpr int size = 100;

struct Node
{
	char code;
	int killCount;
};

class Hitman
{
public:
	void AddNode(char code, int killCount)
	{
		buf[code].code = code;
		buf[code].killCount = killCount;
	}

	void PrintNode(char code)
	{
		std::cout << buf[code].killCount;
	}

private:
	Node buf[size];
};

int main()
{
	Hitman hitman;
	hitman.AddNode('B', 10);
	hitman.AddNode('T', 15);
	hitman.AddNode('S', 12);
	hitman.AddNode('G', 15);
	hitman.AddNode('O', 14);
	hitman.AddNode('D', 13);
	hitman.AddNode('Z', 16);

	hitman.PrintNode('B');
	return 0;
}