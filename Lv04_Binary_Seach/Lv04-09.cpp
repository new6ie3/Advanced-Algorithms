#include <iostream>
#include <queue>

struct Item
{
	int cost;
	bool isGold;

	bool operator<(const Item item) const {
		return this->cost > item.cost;
	}
};

int main()
{
	std::priority_queue<Item> pocket;

	pocket.push({ 1, true });
	pocket.push({3, true});
	pocket.push({3, true});
	pocket.push({4, true});
	pocket.push({9, true});

	int count = 0;
	bool flag = true;
	while (flag)
	{
		int pay = 0;
		for (int i = 0; i < 2; ++i)
		{
			auto item = pocket.top();
			if (item.isGold == false)
			{
				flag = false;
				break;
			}
			
			pocket.pop();
			count++;

			if (i == 1)
			pay = item.cost;
		}

		pocket.push({ pay * 2, false });
	}

	std::cout << count << std::endl;

	return 0;
}