#include <iostream>

int cards[4] = { 2, 5, 1, 6 };
int sum = 0;
int count = 0;
bool used[4] = {};

void recursive(int now = 0)
{
	if (now == 4)
	{
		if (sum > 3000)
			count++;

		return;
	}
	
    for (int i = 0; i < 4; ++i)
    {
        if (used[i])
            continue;

        int addon = pow(10, now);
        used[i] = true; 

        sum += cards[i] * 1000 / addon;

        recursive(now + 1);

        sum -= cards[i] * 1000 / addon;
        used[i] = false;
    }
}

int main()
{
	recursive();
    std::cout << count;

	return 0;
}