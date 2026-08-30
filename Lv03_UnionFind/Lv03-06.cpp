#include <iostream>

int group[5];
char grade[5] = {};

int Find(int x)
{
    if (group[x] == x)
        return x;

    return group[x] = Find(group[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        group[b] = a;
}

void Insert(char rank, char order)
{
    int index = order - '0';

    if (rank >= '0' && rank <= '9')
    {
        int other = rank - '0';
        Union(index, other);
    }
    else if (rank >= 'A' && rank <= 'F')
    {
        grade[index] = rank;
    }
}

int main()
{
    for (int i = 0; i < 5; ++i)
        group[i] = i;

    Insert('3', '2');
    Insert('B', '4');
    Insert('A', '1');
    Insert('3', '4');

    for (int i = 1; i < 5; ++i)
    {
        int idx = Find(i);
        std::cout << grade[idx];
    }


    return 0;
}