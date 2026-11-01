#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
	std::string str = "JASON";
	std::reverse(str.begin(), str.end());

	int idx = 0;
	int res = 0;
	for (char c : str)
	{
		res += (int)c * pow(26, idx);
		idx++;
	}

	return 0;
}