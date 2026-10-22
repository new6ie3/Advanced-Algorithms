#include <iostream>

int main()
{
	int arr[6] = { 5, 3, 8, 1, 2, 7 };

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


	return 0;
}