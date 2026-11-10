#include <iostream>

int dat[10];
int res[10];

int main()
{
	int ary[10] = { 5, 2, 2, 1, 2, };
	for (int i = 0; i < 5; ++i)
	{
		dat[ary[i]]++;
	}

	for (int i = 1; i < 11; ++i)
	{
		dat[i] += dat[i - 1];
		std::cout << dat[i] << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		int idx = dat[ary[i]] - 1;
		res[idx] = ary[i];

		dat[ary[i]]--;
	}
	for (int i = 0; i < 10; ++i)
	{
		if(res[i])
			std::cout << res[i] << ' ';
	}

	return 0;
}