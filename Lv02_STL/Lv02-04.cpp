#include <iostream>
#include <vector>

std::vector<std::vector<int>> vecs =
{
	{1, 6, 0},
	{5, 7},
	{0, 3, 2, 2},
	{9, 2},
	{4, 8},
};

void SortVec(int line)
{
	for (int i = 0; i < vecs[line].size() - 1; ++i)
	{
		for (int j = i + 1; j < vecs[line].size(); ++j)
		{
			if (vecs[line][i] > vecs[line][j])
			{
				int temp = vecs[line][i];
				vecs[line][i] = vecs[line][j];
				vecs[line][j] = temp;
			}
		}
	}
}

int main()
{
	int l1, l2;
	std::cin >> l1 >> l2;

	SortVec(l1);
	SortVec(l2);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << vecs[i][0] << ' ';
	}

	return 0;
}