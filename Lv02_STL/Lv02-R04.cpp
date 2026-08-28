#include <iostream>
#include <time.h>

int main()
{
	srand(unsigned int(time(nullptr)));

	int range = 50, min = 1;
	int answer = rand() % range + min;
	bool flag = false;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int log = rand() % range + min;
		if (answer == log)
		{
			flag = true;
			break;
		}
		else if(answer > log)
		{
			min = log;
			range = range - log + 1;

			std::cout << log << " UP" << std::endl;
		}
		else
		{
			range = log - 1;
			std::cout << log << " Down" << std::endl;
		}
	}

	if (flag)
		std::cout << answer;
	else
		std::cout << min << " ~ " << range;


	return 0;
}