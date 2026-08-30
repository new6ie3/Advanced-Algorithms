#include <iostream>

int population[7] = { 10, 20, 30, 40, 50, 60, 70 };
int group[7];
bool alive[7] = { true, true, true, true, true, true, true };

int Find(int x)
{
    if (group[x] == x)
        return x;

    return group[x] = Find(group[x]);
}

void Alliance(char country1, char country2)
{
    int a = country1 - 'A';
    int b = country2 - 'A';

    a = Find(a);
    b = Find(b);

    if (a != b)
    {
        group[b] = a;
    }
}

void War(char country1, char country2)
{
    int a = Find(country1 - 'A');
    int b = Find(country2 - 'A');

    int populationA = 0;
    int populationB = 0;

    for (int i = 0; i < 7; ++i)
    {
        if (Find(i) == a)
            populationA += population[i];

        if (Find(i) == b)
            populationB += population[i];
    }

    if (populationA > populationB)
    {
        for (int i = 0; i < 7; ++i)
        {
            if (Find(i) == b)
                alive[i] = false;
        }
    }
    else if (populationA < populationB)
    {
        for (int i = 0; i < 7; ++i)
        {
            if (Find(i) == a)
                alive[i] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < 7; ++i)
        group[i] = i;

    Alliance('A', 'C');
    Alliance('F', 'C');
    Alliance('D', 'B');
    Alliance('A', 'F');
    War('D', 'F');

    int count = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (alive[i])
            count++;
    }

    std::cout << count;

    return 0;
}