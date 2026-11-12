#include <iostream>
#include <algorithm>

int main()
{
	std::string str = "JASON";
	std::reverse(str.begin(), str.end());

	int sum = 0;
	int n = 0;
	for (const auto& ch : str)
	{
		sum += (int)ch * pow(26, n);
		n++;
	}

	std::cout << sum;

	return 0;
}