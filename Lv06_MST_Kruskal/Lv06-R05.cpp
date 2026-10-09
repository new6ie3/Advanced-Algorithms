#include <iostream>

char str[] = { 'O', 'X', 'O', 'O', 'X' };

int count = -1;

void Pan(int index)
{
	if (index < 0 || index > 4)
		return;

	str[index] = (str[index] == 'O') ? 'X' : 'O';
}

bool Check()
{
	char first = str[0];
	for (int i = 1; i < 5; ++i)
	{
		if (first != str[i])
			return false;
	}

	return true;
}

void DFS(int now = 0)
{
    if (Check())
    {
        if (count == -1 || now < count)
            count = now;

        return;
    }

    if (now > 5)
        return;

    for (int i = 0; i < 5; ++i)
    {
        Pan(i - 1);
        Pan(i);
        Pan(i + 1);

        DFS(now + 1);

        Pan(i - 1);
        Pan(i);
        Pan(i + 1);
    }
}

int main()
{
	DFS();
	if (count == -1)
		std::cout << "impossible";
	else std::cout << count;

	return 0;
}