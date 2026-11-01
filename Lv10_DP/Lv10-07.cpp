#include <iostream>
#include <vector>

struct Group
{
	char group;
	int id;
};

std::vector<Group> gs =
{
	{'A', 21},
	{'E', 15},
	{'E', 6},
	{'A', 15},
	{'E', 34},
	{'B', 32},
	{'C', 35},
	{'C', 36},
	{'D', 14},
	{'A', 3},

};

std::vector<Group*> groupList;
Group groups[100];
int cnt = 0;

void AddGroup(Group g)
{
	Group* group = nullptr;

	if (cnt < 100)
	{
		groups[cnt] = g;
		group = &groups[cnt];
	}
	else
	{
		group = new Group;
		*group = g;
	}

	groupList.push_back(group);
	cnt++;
}

void PrintID(char c)
{
	for (Group* g : groupList)
	{
		if (g->group == c)
			std::cout << g->id << ' ';
	}
}

int main()
{
	for (Group g : gs)
	{
		AddGroup(g);
	}

	PrintID('A');

	return 0;
}