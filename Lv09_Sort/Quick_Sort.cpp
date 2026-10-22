#include <iostream>
#include <vector>

std::vector<int> vec = { 4, 2, 7, 1, 3, 6, 8 };

void Quick_Sort(int start, int end)
{
    if (start >= end)
        return;

    int pivot = vec[start];

    int left = start + 1;
    int right = end;

    while (left <= right)
    {
        while (left <= end && vec[left] <= pivot)
            left++;

        while (right > start && vec[right] >= pivot)
            right--;

        if (left < right)
            std::swap(vec[left], vec[right]);
    }

    std::swap(vec[start], vec[right]);

    Quick_Sort(start, right - 1);
    Quick_Sort(right + 1, end);
}


int main()
{
	int n = vec.size() - 1;
	Quick_Sort(0, n);

	return 0;
}