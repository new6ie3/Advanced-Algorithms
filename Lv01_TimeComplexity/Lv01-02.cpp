#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* num = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	int min = INT_MAX;
	int* start = &num[0];
	int* end = &num[3];
	int sum = 0;

	for (int* i = start; i <= end; ++i)
		sum += *i;

	for (int i = 0; i < n - 3; ++i)
	{
		if (sum < min)
			min = sum;

		sum +=  -*start + *end;

		start += 1;
		end += 1;
	}

	cout << min << endl;

	delete[] num;

	return 0;
}