#include <iostream>


struct Dinarsor
{
	std::string name;
	int age;
};

Dinarsor ds[8] =
{
	"Sour", 100000005,
	"Dav", 100000002,
	"Nica", 100000003,
	"Timer", 100000006,
	"Pico", 100000015,
	"Topisl", 100000022,
	"Whab", 100000013,
	"Hap", 100000009
};

Dinarsor dinarsors[100];

void HashFunc(Dinarsor d)
{
	dinarsors[d.age % 100000000] = d;
}

void FindDS(int age)
{
	std::cout << dinarsors[age % 100000000].name;
}

int main()
{
	for (int i = 0; i < 8; ++i)
	{
		HashFunc(ds[i]);
	}

	FindDS(100000005);

	return 0;
}