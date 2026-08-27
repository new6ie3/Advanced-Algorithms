#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec = { 5, 4, 5, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 8, 1 };

int main()
{
	int target = *vec.begin();
	int count = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (target == vec[i])
		{
			count++;
			if (count >= 2)
			{
				vec.erase(vec.begin() + i);
				vec.erase(vec.begin() + i - 1);
				vec.erase(vec.begin() + i - 2);
				count = 0;
				i -= 2;
			}
		}
		else
		{
			target = vec[i];
			count = 0;
		}
	}

	std::sort(vec.begin(), vec.end());
	for (int v : vec)
	{
		std::cout << v << ' ';
	}


	return 0;
}