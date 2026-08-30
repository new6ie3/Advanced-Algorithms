#include <iostream>
#include <vector>

std::vector<int> binary_Search_Tree = {0,};

void Insert(int val, int now = 0)
{
	if (now >= binary_Search_Tree.size())
	{
		binary_Search_Tree.resize(now + 1, 0);
	}

	if (binary_Search_Tree[now] == 0)
	{
		binary_Search_Tree[now] = val;
		return;
	}
	
	if (binary_Search_Tree[now] < val)
		Insert(val, now * 2 + 2);
	else
		Insert(val, now * 2 + 1);

}

bool Search(int val, int now = 0)
{
	if (now >= binary_Search_Tree.size())
		return false;

	if (binary_Search_Tree[now] == 0)
		return false;

	if (binary_Search_Tree[now] == val)
		return true;

	if (binary_Search_Tree[now] < val) 
		return Search(val, now * 2 + 2);
	else return Search(val, now * 2 + 1);


	return false;
}

int main()
{
	Insert(1);
	Insert(3);
	Insert(4);
	Insert(7);

	for (int i = 1; i <= 6; ++i)
	{
		bool res = Search(i);
		std::cout << i << " :";
		if (res)
			std::cout << 'O';
		else std::cout << 'X';

		std::cout << std::endl;
	}


	return 0;
}