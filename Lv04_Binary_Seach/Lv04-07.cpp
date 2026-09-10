#include <iostream>
#include <queue>

int main()
{
	std::priority_queue<char> pq;
	std::string str = "DoYouWannaBuildASnowMan?";

	for (char& c : str)
	{
		pq.push(c);
	}

	while (!pq.empty())
	{
		std::cout << pq.top();
		pq.pop();
	}


	return 0;
}