#include <iostream>

int main()
{
	int arr[6] = { 5, 3, 8, 1, 2, 7 };

    for (int i = 1; i < 6; ++i)
    {
        int target = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > target)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = target;
    }


	return 0;
}