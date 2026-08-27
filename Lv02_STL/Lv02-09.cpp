#include <iostream>
#include <algorithm>

int bucket[28] = {};

int main()
{
	std::string ary = "ZZAYYYKBTA";
	std::sort(ary.begin(), ary.end());
	std::reverse(ary.begin(), ary.end());

	int n;
	std::cin >> n;

	int max = 0;
	int val = 0;
	for (int i = 0; i < n; ++i)
	{
		bucket[ary[i]]++;
		if (bucket[ary[i]] > max)
		{
			max = bucket[ary[i]];
			val = ary[i];
		}
	}

	std::cout << (char)val;


	return 0;
}