#include <iostream>
#include <vector>

std::vector<int> vec = { 6, 1, 3, 8, 5 };
int result[5];

void Merge_Sort(int start, int end)
{
	int mid = (start + end) / 2;
	if (start >= end) return;

	Merge_Sort(start, mid);
	Merge_Sort(mid + 1, end);

	int left = start;
	int right = mid + 1;
	int index = 0;

	while (true)
	{
		if (left > mid && right > end) 
			break;
		if (left > mid)
			result[index++] = vec[right++];
		else if (right > end)
			result[index++] = vec[left++];
		else if (vec[left] <= vec[right])
			result[index++] = vec[left++];
		else
			result[index++] = vec[right++];
	}

	for (int i = 0; i < index; i++)
	{
		vec[start + i] = result[i];
	}

}

int main()
{
	int n = vec.size() - 1;
	Merge_Sort(0, n);


	return 0;
}