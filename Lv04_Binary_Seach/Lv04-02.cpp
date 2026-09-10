#include <iostream>
#include <vector>
std::vector<std::string> books = { "Rabbit", "Moon", "Opening", "Alien", "Power", "Ai" };

void Sort_Books()
{
	for (size_t i = 0; i < books.size() - 1; ++i)
	{
		for (size_t j = 0; j < books.size() - 1 - i; ++j)
		{
			if (books[j] > books[j + 1])
			{
				std::string temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
}

void Search_Books(const std::string book, int time, int start = 0, int end = books.size(), int count = 0)
{
	if (start > end || time <= count)
	{
		std::cout << "fail" << std::endl;
		return;
	}

	int mid = (start + end) / 2;
	if (books[mid] == book)
	{
		std::cout << "pass" << std::endl;
	}
	else if (books[mid] < book)
		Search_Books(book, time, mid + 1, end, count + 1);
	else
		Search_Books(book, time, start, mid - 1, count + 1);
}

int main()
{
	Sort_Books();
	Search_Books("Opening", 5);
	Search_Books("Alien", 2);
	Search_Books("Ai", 2);

	return 0;
}