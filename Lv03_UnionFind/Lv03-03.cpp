#include <iostream>

int binary_Search_Tree[15] =
{
	15, 7, 19, 0, 8, 17, 25, 0, 0, 0, 0, 16, 18, 0, 0,
};

int count = 0;
int Find(int value, int now = 0)
{
	count++;
	if (now >= 15) return -1;

	if (value == binary_Search_Tree[now])
		return count;

	else if (value < binary_Search_Tree[now])
		Find(value, now * 2 + 1);
	else
		Find(value, now * 2 + 2);

	count = 0;
}

int main()
{
	int targets[5] = { 8, 16, 6, 25, 30 };
	for (int i = 0; i < 5; ++i)
	{
		int result = Find(targets[i]);
		if (result == -1)
			std::cout << "없음" << std::endl;
		else
			std::cout << targets[i] << " : " << result << "회만에 찾음" << std::endl;
	}

	return 0;
}