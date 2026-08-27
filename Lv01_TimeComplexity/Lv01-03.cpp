#include <iostream>

size_t Solution_1()
{
	int data[10];
	
	return sizeof(data);
}

size_t Solution_2()
{
	double data[3];
	char vect[10];
	int dt[10];

	return sizeof(data) + sizeof(vect) + sizeof(dt);
}

size_t Solution_3()
{
	struct Node
	{
		int x;
		char t;
	};

	Node vect[100];

	return sizeof(vect);
}

size_t Solution_4()
{
	struct Node
	{
		int x;
		char* next;
	};

	Node vect;

	return sizeof(vect);
}

int main()
{
	std::cout << Solution_1() << std::endl;
	std::cout << Solution_2() << std::endl;
	std::cout << Solution_3() << std::endl;
	std::cout << Solution_4() << std::endl;

	return 0;
}