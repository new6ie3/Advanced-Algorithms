#include <iostream>
#include <vector>

std::vector<std::string> mates =
{
	"POP",
	"TOM",
	"MINCODING",
	"MP",
	"BBQ",
	"KFC"
};

struct Mate
{
	std::string name;
	Mate* next;
};

Mate mate[100];
unsigned int cnt = 0;

void InsertMate(std::string name)
{
	if (cnt < 99)
	{
		mate[cnt].name = name;
		mate[cnt].next = nullptr;

		if (cnt != 0)
		{
			mate[cnt - 1].next = &mate[cnt];
		}
		cnt++;
	}
	else
	{
		Mate* newMate = new Mate();
		newMate->name = name;
		newMate->next = nullptr;
	}
}

int main()
{
	InsertMate("POP");
	InsertMate("TOM");
	InsertMate("MC");
	InsertMate("JASON");
	InsertMate("KFC");

	for (std::string name : mates)
	{
		bool isMate = false;
		for (Mate* m = &mate[0]; m != nullptr; m = m->next)
		{
			if (m->name == name)
			{
				isMate = true;
				break;
			}
		}
		(isMate) ? std::cout << "yes" : std::cout << "no";
		std::cout << std::endl;
	}

	return 0;
}