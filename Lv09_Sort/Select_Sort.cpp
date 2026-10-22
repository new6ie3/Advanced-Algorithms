#include <iostream>

int main()
{
	int arr[6] = { 5, 3, 8, 1, 2, 7 };

	for (int i = 0; i < 5; ++i)
	{
		int* target = &arr[i];
		int* min = &arr[i];

		for (int j = i + 1; j < 6; ++j)
		{
			if (*min > arr[j])
				min = &arr[j];
		}

		int temp = *target;
		*target = *min;
		*min = temp;
	}



	return 0;
}