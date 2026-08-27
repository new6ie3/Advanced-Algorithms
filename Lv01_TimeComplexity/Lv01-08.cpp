#include <iostream>
#include <string>

int main()
{
	int p, n;
	std::cin >> p >> n;

	for (int i = 0; i < n; ++i)
	{
		p *= 2;
		std::string str = std::to_string(p);
		std::reverse(str.begin(), str.end());
		p = std::stoi(str);
	}

	std::cout << p << std::endl;

	return 0;
}