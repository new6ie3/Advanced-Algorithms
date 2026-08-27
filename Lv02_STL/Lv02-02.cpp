#include <iostream>

int record[4] = {};
void newRecord(int score)
{
	int j = 3;

	while (j > 0 && record[j - 1] < score)
	{
		record[j] = record[j - 1];
		--j;
	}

	record[j] = score;
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int score;
		std::cin >> score;
		newRecord(score);
	}

	std::cout << "±Ý" << record[0] << std::endl;
	std::cout << "Àº" << record[1] << std::endl;
	std::cout << "µ¿" << record[2] << std::endl;

	return 0;
}